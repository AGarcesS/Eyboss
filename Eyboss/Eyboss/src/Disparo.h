#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

class Disparo {
protected:	
	float radio;
	float longitud;
	Vector2D origen;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	ETSIDI::Sprite* sprite;
	const char* textura;
public:
	Disparo();
	virtual ~Disparo() {}

	float GetRadio();
	Vector2D GetPos();
	void SetPos(float ix, float iy);
	void SetVel (float vx, float vy);

	virtual void Inicializa();
	virtual void Dibuja();
	virtual void Mueve(float t);

	friend class Interaccion;
};