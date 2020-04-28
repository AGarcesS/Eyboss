#pragma once
#include "Protagonista.h"
#include "Caja.h"
#include "Disparo.h"
#include "Pared.h"

class Interaccion {
public:
	Interaccion();
	virtual ~Interaccion() {}

	static bool Colision(Pared p, Vector2D pos, float r, float s);

	static bool Colision(Protagonista& h, Pared p);
	static bool Colision(Protagonista& h, Caja c);

	static bool Colision(Disparo &d, Pared p);
	static bool Colision(Disparo &d, Caja c);
};