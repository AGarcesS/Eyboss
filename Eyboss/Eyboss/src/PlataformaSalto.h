#pragma once
#include "Vector2D.h"
#include "Pared.h"

class PlataformaSalto : public Pared {
public:
	PlataformaSalto();
	virtual ~PlataformaSalto() {}
	void Dibuja(float k = 1);
	

	friend class Interaccion;
};
