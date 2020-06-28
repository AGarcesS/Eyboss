#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

class Disparo {
protected:	
	float radio;
	float longitud;
	int damage;
	float rapidez;
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
	int GetDamage();
	float GetRapidez();
	Vector2D GetPos();
	Vector2D GetVel();
	void SetPos(float ix, float iy);
	void SetVel (float vx, float vy);

	virtual void Inicializa();
	virtual void Dibuja();
	virtual void Mueve(float t);

	friend class Interaccion;
};