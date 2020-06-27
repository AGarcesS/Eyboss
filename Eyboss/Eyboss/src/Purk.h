#pragma once
#include "Personaje.h"

class Purk :public Personaje {
private:
	static int bajas;
public:
	Purk() :Personaje(Personaje::PURK) {
		altura = 1.5f;
		ancho = altura;
		textura = "bin/texturas/purk.png";
		velocidad.x = 0;
		velocidad.y = 0;
		aceleracion.x = 0.0f;
		aceleracion.y = -9.8f;
		col = 3;
		posicion.x = 0;
		posicion.y = 5;
		orientacion = orien_ini = false;
		salto = 4.0f;
		on = false;
		vida = 4;
		daño = 2;
	}
	virtual ~Purk() {}
};
