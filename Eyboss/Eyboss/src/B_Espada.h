#pragma once
#include "Bonus.h"
#include "Personaje.h"

class B_Espada :public Bonus {
private:
	int damage;
public:
	B_Espada();
	virtual ~B_Espada() {}
	
	//void Atacar(Personaje &p);
};