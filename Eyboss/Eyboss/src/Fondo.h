#pragma once
#include "Vector2D.h"
#include "Pared.h"

class Fondo : public Pared {
public:
	Fondo() :Pared(FONDO) {
		rojo = verde = azul = 255;
		textura = "bin/texturas/fondo3.png";
		z = 0;
	}
	virtual ~Fondo() {}
	void Dibuja();

	friend class Interaccion;
};