#pragma once
#include "Bonus.h"

class B_Gancho :public Bonus {
public:
	B_Gancho() :Bonus(0.8, "bin/texturas/gancho.png", "bin/sonidos/recogida.wav", GANCHO) {}
	virtual ~B_Gancho() {}
};