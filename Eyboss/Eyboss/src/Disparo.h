#pragma once
#include "Vector2D.h"

class Disparo {
private:	
	float radio;
	float longitud;
	Vector2D origen;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	Disparo();
	virtual ~Disparo() {}

	float GetRadio();
	Vector2D GetPos();
	void SetPos(float ix, float iy);
	void SetVel (float vx, float vy);
	void Dibuja();
	void Mueve(float t);

	friend class Interaccion;
};