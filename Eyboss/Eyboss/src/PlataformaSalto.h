#pragma once
#include "Vector2D.h"
#include "Pared.h"

class PlataformaSalto : public Pared {
public:
	PlataformaSalto() :Pared(SALTO) {
		rojo = verde = azul = 255;
		textura = "bin/texturas/salto.png";
		z = 0;
	}
	virtual ~PlataformaSalto() {}
	void Dibuja(float k = 1);


	friend class Interaccion;
};
