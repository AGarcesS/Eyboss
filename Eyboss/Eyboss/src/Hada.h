#pragma once
#include "Personaje.h"

class Hada :public Personaje {
private:
public:
	Hada() :Personaje(Personaje::HADA, 1.7f, 1.7f, false, false, false, 4.0f, "bin/texturas/hada.png", 4, 4, true, false, false, false, 0, false, 2, 7.0f) {
//		altura = 1.7f;
//		ancho = altura;
//		textura = "bin/texturas/hada.png";
		velocidad.x = 0;
		velocidad.y = 0;
		vel_seguimiento.x = -3.0f;
		vel_seguimiento.y = 0;
		aceleracion.x = 0.0f;
		aceleracion.y = -9.8f;
//		dist_seguimiento = 7.0f;
//		col = 4;
		posicion.x = 0;
		posicion.y = 5;
//		orientacion = orien_ini = false;
//		salto = 4.0f;
//		on = false;
//		vida = 4;
//		daño = 2;
	}
	virtual ~Hada() {}
};