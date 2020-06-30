#include "ListaEnemigos.h"
#include "Interaccion.h"
#include "Global.h"

ListaEnemigos::ListaEnemigos() {
	numero = 0;
	for (int i = 0; i < MAX_ENEMIGOS; i++)
		lista[i] = 0;
}

bool ListaEnemigos::Agregar(Personaje* p) {
	if (numero < MAX_ENEMIGOS) {
		lista[numero] = p;
		numero++;
		for (int i = 0; i < numero; i++)
		{
			if (lista[i] == p)
				return false;
			else
				return true;
		}
	}
	else
		return false;
}

void ListaEnemigos::Mueve(float t) {
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}

void ListaEnemigos::Dibuja() {
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

void ListaEnemigos::Inicializa() {
	for (int i = 0; i < numero; i++)
		lista[i]->Inicializa();
}

void ListaEnemigos::Colision(Pared pa) {
	for (int i = 0; i < numero; i++) {
		Interaccion::Colision(*lista[i], pa);
		Interaccion::NoCaer(*lista[i], pa);
	}
}

Personaje* ListaEnemigos::Colision(Personaje& p) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::Colision(*lista[i], p))
			return lista[i];
	}
}

void ListaEnemigos::DestruirContenido() {
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaEnemigos::Eliminar(int index) {
	if ((index < 0 || index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaEnemigos::Eliminar(Personaje* p) {
	for (int i = 0; i < numero; i++) {
		if (lista[i] == p) {
			Eliminar(i);
			Global::bajas++;
			return;
		}
	}
}

Personaje* ListaEnemigos::operator [] (int i) {
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;
	return lista[i];
}