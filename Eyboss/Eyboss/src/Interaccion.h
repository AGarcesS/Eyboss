#pragma once
#include "Protagonista.h"
#include "Caja.h"
#include "Disparo.h"
#include "Pared.h"

class Interaccion {
public:
	Interaccion();
	virtual ~Interaccion() {}

	static bool Colision(Pared pa, Vector2D pos, float r);

	static bool Colision(Personaje& p, Pared pa);
	static bool Colision(Personaje& p, Caja c);

	static bool Colision(Disparo &d, Pared pa);
	static bool Colision(Disparo &d, Caja c);
};