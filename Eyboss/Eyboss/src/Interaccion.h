#pragma once
#include "Personaje.h"
#include "Caja.h"
#include "Disparo.h"
#include "O_Espada.h"
#include "O_Gancho.h"
#include "Pared.h"
#include "Bonus.h"

class Interaccion {
public:
	Interaccion();
	virtual ~Interaccion() {}

	static float Distancia(Vector2D p1, Vector2D p2) { return (p1 - p2).modulo(); }

	static bool Colision(Pared &pa, Vector2D pos, float r, float s = 0); //Colisión rectángulo, rectángulo (s para el ancho en caso de no ser igual a la altura)

	static bool Colision(Personaje& p, Pared &pa);
	static bool Colision(Personaje& p, Caja &c);

	
	static bool Colision(Disparo &d, Pared &pa);
	static bool Colision(Disparo &d, Caja &c);
	static bool Colision(Disparo& d, Personaje& p);
	static bool Colision(Bonus& b, Personaje& p);

	static bool Colision(O_Espada& e, Personaje& p);
	static bool Colision(DisparoGancho& dg, Pared& p);

	static bool Colision(Personaje& p1, Personaje& p2);
	static bool Cercania(Personaje& p1, Personaje& p2);
};