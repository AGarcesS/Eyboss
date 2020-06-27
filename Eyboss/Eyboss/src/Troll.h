#pragma once
#include "Personaje.h"

class Troll :public Personaje {
public:
	Troll() :Personaje(Personaje::TROLL) {
		altura = 2.5f;
		ancho = altura;
		textura = "bin/texturas/troll.png";
		velocidad.x = 0;
		velocidad.y = 0;
		aceleracion.x = 0.0f;
		aceleracion.y = -9.8f;
		col = 4;
		posicion.x = 0;
		posicion.y = 5;
		orientacion = orien_ini = false;
		salto = 1.5f;
		on = false;
		vida = 8;
		daño = 4;
	}
	virtual ~Troll() {}
};