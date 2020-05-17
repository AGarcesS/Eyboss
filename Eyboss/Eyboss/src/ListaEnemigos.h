#pragma once
#define MAX_ENEMIGOS 50
#include "Personaje.h"
#include "Pared.h"
#include "Caja.h"

class ListaEnemigos {
private:
	Personaje* lista[MAX_ENEMIGOS];
	int numero;
public:
	ListaEnemigos();
	virtual ~ListaEnemigos() {}

	bool Agregar(Personaje* p);
	void DestruirContenido();
	void Eliminar(int index);
	void Eliminar(Personaje* p);
	void Mueve(float t);
	void Dibuja();
	void Inicializa();

	Personaje* Colision(Pared pa);
	Personaje* Colision(Caja c);
	Personaje* operator [] (int i);
};