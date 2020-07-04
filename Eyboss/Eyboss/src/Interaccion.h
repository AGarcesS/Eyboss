#pragma once
#include "Personaje.h"
#include "Disparo.h"
#include "O_Espada.h"
#include "O_Gancho.h"
#include "Pared.h"
#include "Bonus.h"

class Interaccion {
public:
	Interaccion();
	virtual ~Interaccion() {}


	static bool Colision(Pared &pa, Vector2D pos, float r, float s = 0); //Colisión rectángulo, rectángulo (s para el ancho en caso de no ser igual a la altura)

	static bool Colision(Personaje& p, Pared &pa);

	
	static bool Colision(Disparo &d, Pared &pa);
	static bool Colision(Disparo& d, Personaje& p);
	static bool Colision(Bonus& b, Personaje& p);

	static bool Colision(O_Espada& e, Personaje& p);
	static int Colision(DisparoGancho& dg, Pared p, Personaje& nyes);

	static bool Colision(Personaje& p1, Personaje& p2);
	static bool Cercania(Personaje& p1, Personaje& p2);
	static bool NoCaer(Personaje& p, Pared& pa);
};