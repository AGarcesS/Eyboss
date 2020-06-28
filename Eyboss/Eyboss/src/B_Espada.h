#pragma once
#include "Bonus.h"

class B_Espada :public Bonus {
public:
	B_Espada() :Bonus(Bonus::ESPADA) {
		lado = 0.8;
		textura = "bin/texturas/espada.png";
		audio = "bin/sonidos/recogida.wav";
	}
	virtual ~B_Espada() {}
};