#pragma once
#include "Bonus.h"
#include "Personaje.h"

class B_Tirachinas :public Bonus {
private:
	int municion;
public:
	B_Tirachinas() :Bonus(0.8, "bin/texturas/tirachinas.png", "bin/sonidos/recogida.wav",TIRACHINAS), municion(5) {}
	virtual ~B_Tirachinas() {}
	
	void Accion(Personaje& p);
};