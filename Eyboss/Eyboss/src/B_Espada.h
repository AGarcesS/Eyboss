#pragma once
#include "Bonus.h"

class B_Espada :public Bonus {
public:
	B_Espada() :Bonus(0.8, "bin/texturas/espada.png", "bin/sonidos/recogida.wav", Bonus::ESPADA) {}
	virtual ~B_Espada() {}
};