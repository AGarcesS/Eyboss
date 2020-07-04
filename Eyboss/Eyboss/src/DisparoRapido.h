#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "Disparo.h"

class DisparoRapido : public Disparo {
public:
	DisparoRapido() {
		radio = 0.5;
		damage = 1;
		rapidez = 9.0f;
		posicion.x = 0;
		posicion.y = 0;
		velocidad.x = 10;
		velocidad.y = 0;
		aceleracion.x = 0;
		aceleracion.y = 0;
		origen.x = 0;
		origen.y = 0;
		longitud = 0;
		textura = "bin/texturas/rapido.png";
	}
	virtual ~DisparoRapido() {}

	friend class Interaccion;
};
