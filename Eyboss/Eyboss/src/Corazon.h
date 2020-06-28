#pragma once
#include "ETSIDI.h"
#include "Bonus.h"

class Corazon : public Bonus {
private:
	int curacion;
	ETSIDI::Sprite* corazon;
public:
	Corazon() :Bonus(CORAZON) {
		curacion = 3;
		lado = 0.8f;
		textura = "bin/texturas/clleno.png";
		audio = "bin/sonidos/vida.wav";
	}
	virtual ~Corazon() {}
	void Accion(Personaje &p);
};