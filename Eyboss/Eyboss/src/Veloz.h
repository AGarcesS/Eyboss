#pragma once
#include "Personaje.h"

class Veloz :public Personaje {
public:
	Veloz() :Personaje(Personaje::VELOZ, 1.0f, 1.0f, false, false, false, 6.0f, "bin/texturas/veloz.png", 1, 4, true, false, false, false, 0, false, 1, 7.0f) {
//		altura = 1.0f;
//		ancho = altura;
//		textura = "bin/texturas/veloz.png";
		velocidad.x = 0;
		velocidad.y = 0;
		vel_seguimiento.x = 4;
		vel_seguimiento.y = 0;
//		dist_seguimiento = 7.0f;
		aceleracion.x = 0.0f;
		aceleracion.y = -9.8f;
//		col = 4;
		posicion.x = 0;
		posicion.y = 5;
//		orientacion = orien_ini = false;
//		salto = 6.0f;
//		on = false;
//		vida = 1;
//		daño = 1;
	}
	virtual ~Veloz() {}
};