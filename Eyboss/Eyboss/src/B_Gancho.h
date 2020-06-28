#pragma once
#include "Bonus.h"

class B_Gancho :public Bonus {
public:
	B_Gancho() :Bonus(GANCHO) {
		lado = 0.8;
		textura = "bin/texturas/gancho.png";
		audio = "bin/sonidos/recogida.wav";
	}
	virtual ~B_Gancho() {}
};
