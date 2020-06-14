#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"

class Bonus {
protected:	
	float lado;
	Vector2D posicion;
	ETSIDI::Sprite* sprite;
	const char* textura;
	const char* audio;	
public:
	Bonus();
	virtual ~Bonus() {}

	void SetPos(float ix, float iy);

	virtual void Inicializa() {}
	void Dibuja();
	void Audio();
	virtual void DestruirContenido() {}

	friend class Interaccion;
};