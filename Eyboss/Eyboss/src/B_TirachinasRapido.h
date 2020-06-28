#pragma once
#include "Bonus.h"
#include "Personaje.h"

class B_TirachinasRapido :public Bonus {
private:
	int municion;
public:
	B_TirachinasRapido() :Bonus(TIRACHINAS_RAPIDO) {
		lado = 0.8;
		municion = 2;
		textura = "bin/texturas/tirachinasRapido.png";
		audio = "bin/sonidos/recogida.wav";
	}
	virtual ~B_TirachinasRapido() {}

	void Accion(Personaje& p);
};