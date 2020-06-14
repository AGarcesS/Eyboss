#include "ListaDisparos.h"
#include "Interaccion.h"

ListaDisparos::ListaDisparos() {
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		lista[i] = 0;
}

bool ListaDisparos::Agregar(Disparo* d) {
	if (numero < MAX_DISPAROS) {
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

void ListaDisparos::DestruirContenido() {
	for (int i = 0; i < numero; i++)
		delete lista[i];
	numero = 0;
}

void ListaDisparos::Eliminar(int index) {
	if ((index < 0 || index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}

void ListaDisparos::Eliminar(Disparo* d) {
	for (int i = 0; i < numero; i++) {
		if (lista[i] == d) {
			Eliminar(i);
			return;
		}
	}
}

void ListaDisparos::Mueve(float t) {
	for (int i = 0; i < numero; i++)
		lista[i]->Mueve(t);
}

void ListaDisparos::Dibuja() {
	for (int i = 0; i < numero; i++)
		lista[i]->Dibuja();
}

Disparo* ListaDisparos::Colision(Pared p) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::Colision(*lista[i], p))
			return lista[i];
	}		
	return 0;
}

Disparo* ListaDisparos::Colision(Caja c) {
	for (int i = 0; i < numero; i++) {
		if (Interaccion::Colision(*lista[i], c))
			return lista[i];
	}
	return 0;
}

Disparo* ListaDisparos::operator [] (int i) {
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;
	return lista[i];
}