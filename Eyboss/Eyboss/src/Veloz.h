#pragma once
#include "Personaje.h"

class Veloz :public Personaje {
public:
	Veloz() :Personaje(Personaje::VELOZ) {
		altura = 1.0f;
		ancho = altura;
		textura = "bin/texturas/veloz.png";
		velocidad.x = 0;
		velocidad.y = 0;
		aceleracion.x = 0.0f;
		aceleracion.y = -9.8f;
		col = 4;
		posicion.x = 0;
		posicion.y = 5;
		orientacion = orien_ini = false;
		salto = 0;
		on = false;
		vida = 8;
	}
	virtual ~Veloz() {}
};