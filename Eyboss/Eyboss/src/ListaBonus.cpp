#include "ListaBonus.h"
#include "Interaccion.h"

ListaBonus::ListaBonus() {
	numero = 0;
	for (int i = 0; i < MAX_BONUS; i++)
		lista[i] = 0;
}

bool ListaBonus::Agregar(Bonus* p) {
	if (numero < MAX_BONUS) {
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

void ListaBonus::DestruirContenido() {
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaBonus::Eliminar(int index) {
	if ((index < 0 || index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaBonus::Eliminar(Bonus* p) {
	for (int i = 0; i < numero; i++) {
		if (lista[i] == p) {
			Eliminar(i);
			return;
		}
	}
}

void ListaBonus::Dibuja() {
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

void ListaBonus::Audio() {
	for (int i = 0; i < numero; i++)
		lista[i]->Audio();
}

void ListaBonus::Inicializa() {
	for (int i = 0; i < numero; i++)
		lista[i]->Inicializa();
}

Bonus* ListaBonus::operator [] (int i) {
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;
	return lista[i];
}