#pragma once
#include "Personaje.h"
#include "Caja.h"
#include "Disparo.h"
#include "Pared.h"
#include "Bonus.h"

class Interaccion {
public:
	Interaccion();
	virtual ~Interaccion() {}

	static bool Colision(Pared pa, Vector2D pos, float r, float s); //Colisión rectángulo, rectángulo (s para el ancho en caso de no ser igual a la altura)

	static bool Colision(Personaje& p, Pared pa);
	static bool Colision(Personaje& p, Caja c);
	static bool Colision(Personaje p, Bonus b);

	static bool Colision(Disparo &d, Pared pa);
	static bool Colision(Disparo &d, Caja c);
};