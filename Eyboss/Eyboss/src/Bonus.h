#pragma once
#include "Vector2D.h"

class Bonus {
private:	
	float lado;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	Bonus();
	virtual ~Bonus() {}

	void SetPos(float ix, float iy);
	void Dibuja();
	void Mueve(float t);
};