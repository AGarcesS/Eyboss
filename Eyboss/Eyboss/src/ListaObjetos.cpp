#include "ListaObjetos.h"

ListaObjetos::ListaObjetos() {
	numero = 0;
	for (int i = 0; i < n_objetos; i++)
		lista[i] = 0;
}

bool ListaObjetos::Agregar(Objeto* o) {
	if (numero < n_objetos) {
		lista[numero] = o;
		numero++;
		return true;
	}
	return false;
}

void ListaObjetos::DestruirContenido() {
	for (int i = 0; i < numero; i++) {
		lista[i]->DestruirContenido();
		delete lista[i];
	}
	numero = 0;
}

void ListaObjetos::Eliminar(int index) {
	if ((index < 0 || index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaObjetos::Eliminar(Objeto* o) {
	for (int i = 0; i < numero; i++) {
		if (lista[i] == o) {
			Eliminar(i);
		}
	}
}

void ListaObjetos::Dibuja() {
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

Objeto* ListaObjetos::operator [] (int i) {
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;
	return lista[i];
}

void ListaObjetos::Ataca(Personaje& p) {
	for (int i = 0; i < numero; i++)
		lista[i]->Ataca(p);
}

void ListaObjetos::Colision(ListaPlataformas& p) {
	for (int i = 0; i < numero; i++)
		lista[i]->Colision(p);
}

void ListaObjetos::Colision(ListaEnemigos& p) {
	for (int i = 0; i < numero; i++) {
		lista[i]->Colision(p);
	}
}

void ListaObjetos::Colision(Caja& c) {
	for (int i = 0; i < numero; i++)
		lista[i]->Colision(c);
}

void ListaObjetos::Mueve(float t) {
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}