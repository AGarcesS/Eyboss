#include "O_Gancho.h"
#include "glut.h"
#include "Interaccion.h"


bool O_Gancho::Agregar(DisparoGancho* d) {
	if (numero < MAX_GANCHOS) {
		lista[numero] = d;
		numero++;
		for (int i = 0; i < numero; i++)
		{
			if (lista[i] == d) {
				ETSIDI::play("bin/sonidos/shoot.wav");
				return false;
			}
			else
				return true;
		}
	}
	else
		return false;
}

void O_Gancho::DestruirContenido() {
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void O_Gancho::Eliminar(int index) {
	if ((index < 0 || index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void O_Gancho::Eliminar(DisparoGancho* d) {
	for (int i = 0; i < numero; i++) {
		if (lista[i] == d) {
			Eliminar(i);
			return;
		}
	}
}

void O_Gancho::Inicializa() {
	for (int i = 0; i < numero; i++)
		lista[i]->Inicializa();
}

void O_Gancho::Mueve(float t){
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);	
}

void O_Gancho::Dibuja() {
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

DisparoGancho* O_Gancho::operator [] (int i) {
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;
	return lista[i];
}

void O_Gancho::Ataca(Personaje& p) {
	DisparoGancho* dg = new DisparoGancho();
	dg->SetPosOr(p.GetPos().x, p.GetPos().y);
	dg->SetPos(p.GetPos().x, p.GetPos().y);
	if (p.GetOrientacion()) {
		dg->SetOrientacion(true);
		dg->SetVel(7.0f, 7.0f);
	}
	else {
		dg->SetOrientacion(false);
		dg->SetVel(-7.0f, 7.0f);
	}
	Agregar(dg);
	Inicializa();
	dg->SetF(true);
	p.SetMovimiento(false);
	p.SetVel(0, 0);
	p.SetAcel(0, 0);
}

void O_Gancho::Colision(ListaPlataformas& l, Personaje* nyes) {
	int col;
	for (int i = 0; i < l.getNumero(); i++) {
		for (int j = 0; j < numero;j++) {
			col = Interaccion::Colision(*lista[j], *l[i], *nyes);
			if (col = 2 && Interaccion::Distancia(nyes->GetPos(), lista[j]->GetPos()) < 1 && !lista[j]->GetF() && !lista[j]->GetPared()) {
				lista[j]->SetVel(0, 0);
				nyes->SetMovimiento(true);
				Eliminar(lista[j]);

			}
			if (col = 1 && Interaccion::Distancia(nyes->GetPos(), lista[j]->GetPos()) < 1 && !lista[j]->GetF() && lista[j]->GetPared()) {
				nyes->SetMovimiento(true);
				nyes->SetPos(lista[j]->GetPos().x, lista[j]->GetPos().y + 2.5);
				nyes->SetVel(0, 0);
				Eliminar(lista[j]);
			}
		}
	}

}