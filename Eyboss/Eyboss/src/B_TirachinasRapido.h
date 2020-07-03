#pragma once
#include "Bonus.h"
#include "Personaje.h"

class B_TirachinasRapido :public Bonus {
private:
	int municion;
public:
	B_TirachinasRapido() :Bonus(0.8, "bin/texturas/tirachinasRapido.png", "bin/sonidos/recogida.wav",TIRACHINAS_RAPIDO), municion(2) {}
	virtual ~B_TirachinasRapido() {}

	void Accion(Personaje& p);
};