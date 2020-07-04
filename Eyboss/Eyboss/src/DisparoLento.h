#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "Disparo.h"

class DisparoLento : public Disparo {
public:
	DisparoLento() {
		radio = 0.5;
		damage = 3;
		rapidez = 5.0f;
		posicion.x = 0;
		posicion.y = 0;
		velocidad.x = 4;
		velocidad.y = 0;
		aceleracion.x = 0;
		aceleracion.y = 0;
		origen.x = 0;
		origen.y = 0;
		longitud = 0;
		textura = "bin/texturas/lento2.png";
	}
	virtual ~DisparoLento() {}

	friend class Interaccion;
};
