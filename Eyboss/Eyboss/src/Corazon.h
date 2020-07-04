#pragma once
#include "ETSIDI.h"
#include "Bonus.h"

class Corazon : public Bonus {
private:
	int curacion;
public:
	Corazon() :Bonus(0.8, "bin/texturas/clleno.png", "bin/sonidos/vida.wav", CORAZON), curacion(2) {}
	virtual ~Corazon() {}
	void Accion(Personaje &p);
};