#pragma once
#include "Bonus.h"
#include "Personaje.h"

class B_Tirachinas :public Bonus {
private:
	int municion;
public:
	B_Tirachinas() :Bonus(TIRACHINAS) {
		lado = 0.8;
		municion = 5;
		textura = "bin/texturas/tirachinas.png";
		audio = "bin/sonidos/recogida.wav";
	}
	virtual ~B_Tirachinas() {}
	
	void Accion(Personaje& p);
};