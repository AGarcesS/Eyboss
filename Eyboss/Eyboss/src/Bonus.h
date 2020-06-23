#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"
#include "Personaje.h"

class Bonus {
protected:	
	float lado;
	Vector2D posicion;
	ETSIDI::Sprite* sprite;
	const char* textura;
	const char* audio;	
	int index; //índice de cada arma
public:
	Bonus();
	virtual ~Bonus() {}

	int GetIndex();
	void SetPos(float ix, float iy);

	void Inicializa();
	void Dibuja();
	void Audio();
	virtual void Accion(Personaje& p) {}

	friend class Interaccion;
};