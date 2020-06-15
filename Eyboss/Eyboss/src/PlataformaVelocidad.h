#pragma once
#include "Vector2D.h"
#include "Pared.h"

class PlataformaVelocidad : public Pared {
public:
	PlataformaVelocidad();
	virtual ~PlataformaVelocidad() {}
	void Dibuja(float k = 1);


	friend class Interaccion;
};

