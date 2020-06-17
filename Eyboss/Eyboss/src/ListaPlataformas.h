#pragma once
#define MAX_PLATAFORMAS 50
#include "Pared.h"

class ListaPlataformas {
private:
	Pared* lista[MAX_PLATAFORMAS];
	int numero;
public:
	ListaPlataformas();
	virtual ~ListaPlataformas() {}

	bool Agregar(Pared* p);
	void DestruirContenido();
	void Eliminar(int index);
	void Eliminar(Pared* p);
	void Dibuja();

	Pared* operator[](int i);
	int getNumero() { return numero; }
};
