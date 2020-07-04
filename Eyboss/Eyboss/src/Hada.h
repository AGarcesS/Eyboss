#pragma once
#include "Personaje.h"

class Hada :public Personaje {
public:
	Hada() :Personaje(Personaje::HADA, 1.7f, 1.7f, false, false, false, 4.0f, "bin/texturas/hada.png", 4, 4, true, false, false, false, 0, 0, 1, 7.0f) {
		velocidad.x = 0;
		velocidad.y = 0;
		vel_seguimiento.x = 3.0f;
		vel_seguimiento.y = 0;
		aceleracion.x = 0.0f;
		aceleracion.y = -9.8f;		
		posicion.x = 0;
		posicion.y = 5;
	}
	virtual ~Hada() {}
};