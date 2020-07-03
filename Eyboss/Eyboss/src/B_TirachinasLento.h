#pragma once
#include "Bonus.h"
#include "Personaje.h"

class B_TirachinasLento :public Bonus {
private:
	int municion;
public:
	B_TirachinasLento() :Bonus(0.8, "bin/texturas/tirachinasLento.png", "bin/sonidos/recogida.wav",TIRACHINAS_LENTO), municion(2) {}
	virtual ~B_TirachinasLento() {}

	void Accion(Personaje& p);
};
