#pragma once
#include "Vector2D.h"

class Texto {
public:
	const char* text;
	Vector2D posicion;
	float rojo;
	float verde;
	float azul;

public:
	Texto();
	Texto(const char* text, Vector2D pos, float r, float v, float a);
	void Imprimir();
};