#pragma once
#include "Bonus.h"
#include "Personaje.h"

class B_TirachinasRapido :public Bonus {
public:
	B_TirachinasRapido();
	virtual ~B_TirachinasRapido() {}

	void Accion(Personaje& p);
};