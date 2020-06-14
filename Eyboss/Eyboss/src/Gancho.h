#pragma once
#include "Vector2D.h"

class Gancho {
private:
	float radio;
	float altura;
	float ancho;
	float alturamaxima;
	Vector2D origen;
	Vector2D posicion;
	Vector2D velocidad;
public:
	Gancho();
	virtual ~Gancho() {};
	void SetVel(float vx, float vy);
	void SetPos(Vector2D pos);
	void GetO(Vector2D pos);
	void Dibuja();
	void Mueve(float t);

	friend class Interaccion;
};