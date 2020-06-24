#pragma once
#include "Bonus.h"
#include "Personaje.h"

class B_Tirachinas :public Bonus {
public:
	B_Tirachinas();
	virtual ~B_Tirachinas() {}
	
	void Accion(Personaje& p);
};