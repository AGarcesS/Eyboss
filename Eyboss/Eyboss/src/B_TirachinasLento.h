#pragma once
#include "Bonus.h"
#include "Personaje.h"

class B_TirachinasLento :public Bonus {
public:
	B_TirachinasLento();
	virtual ~B_TirachinasLento() {}

	void Accion(Personaje& p);
};
