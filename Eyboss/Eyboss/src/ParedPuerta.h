#pragma once
#include "Vector2D.h"
#include "Pared.h"

class ParedPuerta : public Pared {
public:
	ParedPuerta() :Pared(PUERTA) {
		rojo = verde = azul = 255;
		textura = "bin/texturas/puerta.png";
		z = 0;
	}
	virtual ~ParedPuerta() {}

	friend class Interaccion;
};