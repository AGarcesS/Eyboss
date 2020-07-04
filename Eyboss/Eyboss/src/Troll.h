#pragma once
#include "Personaje.h"

class Troll :public Personaje {
public:
	Troll() :Personaje(Personaje::TROLL, 2.5f, 2.5f, false, false, false, 8.0f, "bin/texturas/troll.png", 1.5f, 4, true, false, false, false, 0, 0, 3, 7.0f) {
		//altura = 2.5f;
		//ancho = altura;
		//textura = "bin/texturas/troll.png";
		velocidad.x = 0;
		velocidad.y = 0;
		vel_seguimiento.x = 1.5f;
		vel_seguimiento.y = 0;
		//dist_seguimiento = 7.0f;
		aceleracion.x = 0.0f;
		aceleracion.y = -9.8f;
		//col = 4;
		posicion.x = 0;
		posicion.y = 5;
		//orientacion = orien_ini = false;
		//salto = 1.5f;
		//on = false;
		//vida = 8;
		//daño = 3;
	}
	virtual ~Troll() {}
};