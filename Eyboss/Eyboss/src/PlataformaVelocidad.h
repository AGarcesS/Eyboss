#pragma once
#include "Vector2D.h"
#include "Pared.h"

class PlataformaVelocidad : public Pared {
public:
	PlataformaVelocidad() :Pared(VELOCIDAD) {
		rojo = verde = azul = 255;
		textura = "bin/texturas/speed.png";
		z = 0;
	}
	virtual ~PlataformaVelocidad() {}
	void Dibuja(float k = 1);


	friend class Interaccion;
};
