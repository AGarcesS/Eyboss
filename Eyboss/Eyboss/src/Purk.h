#pragma once
#include "Personaje.h"

class Purk :public Personaje {
private:
	static int bajas;
public:
	Purk() :Personaje(Personaje::PURK, 1.5f, 1.5f, false, false, false, 4.0f, "bin/texturas/purk.png", 4, 3, true, false, false, false, 0, false, 2, 7.0f) {
//		altura = 1.5f;
//		ancho = altura;
//		textura = "bin/texturas/purk.png";
		velocidad.x = 0;
		velocidad.y = 0;
		vel_seguimiento.x = 3.5f;
		vel_seguimiento.y = 0;
//		dist_seguimiento = 7.0f;
		aceleracion.x = 0.0f;
		aceleracion.y = -9.8f;
//		col = 3;
		posicion.x = 0;
		posicion.y = 5;
//		orientacion = orien_ini = false;
//		salto = 4.0f;
//		on = false;
//		vida = 4;
//		daño = 2;
	}
	virtual ~Purk() {}
};

/*
Protagonista():Personaje(Personaje::PROTAGONISTA, 1.8f, altura, false, orientacion, false, 8.0f, "bin/texturas/eris_der2.png", 10, col, true, false, false, false, 0, false)
*/