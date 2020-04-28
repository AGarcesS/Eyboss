#pragma once
#define MAX_DISPAROS 50
#include "Disparo.h"
#include "Caja.h"

class ListaDisparos {
private:
	Disparo* lista[MAX_DISPAROS];
	int numero;
public:
	ListaDisparos();
	virtual ~ListaDisparos() {}

	bool Agregar(Disparo* d);
	void DestruirContenido();
	void Eliminar(int index);
	void Eliminar(Disparo* d);
	void Mueve(float t);
	void Dibuja();
	Disparo* Colision(Pared p);
	Disparo* Colision(Caja c);
	Disparo* operator [] (int i);
};