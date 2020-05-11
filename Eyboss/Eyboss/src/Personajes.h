#pragma once
#include "Vector2D.h"

class Personajes
{
protected:
	float altura;
	float ancho;
	bool orientacion; //true-> derecha, false-> izquierda
	int vida;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

public:
	Personajes();
	virtual ~Personajes();

	int GetVida();
	Vector2D GetPos();
	Vector2D GetVel();
	Vector2D GetAcel();
	float GetAltura();
	bool GetOrientacion();

	void SetPos(float px, float py);
	void SetVel(float vx, float vy);
	void SetAcel(float ax, float ay);
	void SetOrientacion(bool ori);

	void Dibuja();
	void Mueve(float t);
};