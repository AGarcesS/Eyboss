#include "ListaPlataformas.h"
#include "Interaccion.h"

ListaPlataformas::ListaPlataformas() {
	numero = 0;
	for (int i = 0; i < MAX_PLATAFORMAS; i++)
		lista[i] = 0;
}

bool ListaPlataformas::Agregar(Pared* p) {
	if (numero < MAX_PLATAFORMAS) {
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

void ListaPlataformas::DestruirContenido() {
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaPlataformas::Eliminar(int index) {
	if ((index < 0 || index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaPlataformas::Eliminar(Pared* p) {
	for (int i = 0; i < numero; i++) {
		if (lista[i] == p) {
			Eliminar(i);
			return;
		}
	}
}

void ListaPlataformas::Dibuja() {
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

Pared* ListaPlataformas::operator [] (int i) {
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;
	return lista[i];
}