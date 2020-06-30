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
		vel_seguimiento.x = 3.5f;
		vel_seguimiento.y = 0;
		dist_seguimiento = 7.0f;
		dist_disparo = 12.0f;
		aceleracion.x = 0.0f;
		aceleracion.y = -9.8f;
		col = 3;
		posicion.x = 0;
		posicion.y = 5;
		orientacion = orien_ini = false;
		salto = 4.0f;
		on = false;
		vida = 4;
		da�o = 2;
	}
	virtual ~Purk() {}
};
