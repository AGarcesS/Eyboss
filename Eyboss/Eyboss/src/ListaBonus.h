#pragma once
#define MAX_BONUS 50
#include "Bonus.h"
#include "Personaje.h"

class ListaBonus {
private:
	Bonus* lista[MAX_BONUS];
	int numero;
public:
	ListaBonus();
	virtual ~ListaBonus() {}

	bool Agregar(Bonus* b);
	void DestruirContenido();
	void Eliminar(int index);
	void Eliminar(Bonus* b);
	void Dibuja();
	void Inicializa();

	Bonus* operator[](int i);

	int getNumero() { return numero; }
};