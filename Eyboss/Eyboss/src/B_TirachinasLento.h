#pragma once
#include "Bonus.h"
#include "Personaje.h"

class B_TirachinasLento :public Bonus {
private:
	int municion;
public:
	B_TirachinasLento() :Bonus(TIRACHINAS_LENTO) {
		lado = 0.8;
		municion = 2;
		textura = "bin/texturas/tirachinasLento.png";
		audio = "bin/sonidos/recogida.wav";
	}
	virtual ~B_TirachinasLento() {}

	void Accion(Personaje& p);
};
