#pragma once
#include "ETSIDI.h"
#include "Bonus.h"

class Llave : public Bonus {
public:
	Llave() :Bonus(0.8, "bin/texturas/key.png", "bin/sonidos/recogida.wav", LLAVE) {}
	virtual ~Llave() {}
	void Accion(Personaje& p);
};