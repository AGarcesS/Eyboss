#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"
#include "Personaje.h"

class Bonus {
public:
	enum bonus { BONUS = 0, TIRACHINAS, ESPADA, CORAZON, TIRACHINAS_LENTO, TIRACHINAS_RAPIDO, GANCHO };
protected:	
	bonus tipo;
	float lado;
	Vector2D posicion;
	ETSIDI::Sprite* sprite;
	const char* textura;
	const char* audio;	
public:
	Bonus(bonus b = BONUS) :tipo(b) { }
	virtual ~Bonus() {}

	bonus GetTipo() { return tipo; }
	void SetPos(float ix, float iy);

	void Inicializa();
	void Dibuja();
	void Audio();
	virtual void Accion(Personaje& p) {}

	friend class Interaccion;
};