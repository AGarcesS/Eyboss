#pragma once
#include "Vector2D.h"

class Pared {
public:
	enum plataformas { NORMAL = 0, SALTO, VELOCIDAD, FONDO, PUERTA };
protected:
	plataformas tipo;	
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;	
	Vector2D limite1;
	Vector2D limite2;
	const char* textura;
	float z;
	float k; //zoom
	
	Vector2D CPlano1;
	Vector2D CPlano2;
public:
	//Pared();
	Pared(plataformas t = NORMAL) :tipo(t) {
		rojo = verde = azul = 255;
		textura = "bin/texturas/floor.png";
		z = 0;
	}
	plataformas GetTipo() { return tipo; }
	virtual ~Pared() {}

	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	void SetPos(float x1, float y1, float x2, float y2/*, float f*/);
	/*void SetK(float k);*/
	/*void SetTextura(const char* text);*/
	virtual void Dibuja();
	float distanciap_r(Vector2D recta1, Vector2D recta2, Vector2D punto, Vector2D* dir = 0);
	//float distancia(Vector2D punto, Vector2D* direccion = 0);
	/*void SetZ(float z) { this->z = z; }*/
	friend class Interaccion;
};