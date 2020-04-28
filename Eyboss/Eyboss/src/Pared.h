#pragma once
#include "Vector2D.h"

class Pared {
private:	
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;	
	Vector2D limite1;
	Vector2D limite2;
	const char* textura;
	
	Vector2D CPlano1;
	Vector2D CPlano2;
public:
	Pared();
	virtual ~Pared() {}

	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float x1, float y1, float x2, float y2);
	void SetTextura(const char* text);
	void Dibuja();
	float distanciap_r(Vector2D punto1, Vector2D punto2, Vector2D punto3, Vector2D* dir);
	//float distancia(Vector2D punto, Vector2D* direccion = 0);

	friend class Interaccion;
};