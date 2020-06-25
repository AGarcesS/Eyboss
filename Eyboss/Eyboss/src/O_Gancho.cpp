#include "O_Gancho.h"
#include "glut.h"
#include "Interaccion.h"


bool O_Gancho::Agregar(Disparo* d) {
	if (numero < MAX_GANCHOS) {
		lista[numero] = d;
		numero++;
		for (int i = 0; i < numero; i++)
		{
			if (lista[i] == d)
				return false;
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

void O_Gancho::Eliminar(Disparo* d) {
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
/*
Disparo* O_Gancho::Colision(Pared p) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::Colision(*lista[i], p))
			return lista[i];
	}		
	return 0;
}
*/

Disparo* O_Gancho::operator [] (int i) {
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;
	return lista[i];
}

void O_Gancho::Ataca(Personaje& p) {
	DisparoGancho* dg = new DisparoGancho();
	dg->SetPosOr(p.GetPos().x, p.GetPos().y);
	if (p.GetOrientacion())
		dg->SetVel(7.0f, 7.0f);
	else
		dg->SetVel(-7.0f, 7.0f);
	Agregar(dg);
	Inicializa();
	ETSIDI::play("bin/sonidos/shoot.wav");
}


/*
void O_Gancho::Ataca(Personaje& p) {
	orientacion = p.GetOrientacion();

	if (orientacion)
		velocidad.x = 7;
	else
		velocidad.x = -7;

	velocidad.y = 7;

	posorigen.x = posicion.x = p.GetPos().x;
	posorigen.y = posicion.y = p.GetPos().y;

}
*/

void O_Gancho::Colision(Caja &c) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::Colision(*lista[i], c))
			Eliminar(lista[i]);
	}
}

void O_Gancho::Colision(ListaPlataformas& l) {
    for (int i = 0; i < l.getNumero(); i++) {
		for(int j=0; j<numero;j++){
			Interaccion::Colision(*lista[j], *l[i]);
        }
    }
}