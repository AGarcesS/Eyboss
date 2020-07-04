#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"
#include "Personaje.h"

class Bonus {
public:
	enum bonus { BONUS = 0, TIRACHINAS, ESPADA, CORAZON, TIRACHINAS_LENTO, TIRACHINAS_RAPIDO, GANCHO, LLAVE };
protected:	
	bonus tipo;
	float lado;
	Vector2D posicion;
	ETSIDI::Sprite* sprite;
	const char* textura;
	const char* audio;	
public:
	Bonus(float lad, const char* text, const char* aud, bonus b = BONUS) : lado(lad), textura(text), audio(aud), tipo(b) { }
	virtual ~Bonus() {}

	bonus GetTipo() { return tipo; }
	void SetPos(float ix, float iy);

	void Inicializa();
	void Dibuja();
	void Audio();
	virtual void Accion(Personaje& p) {} //acción relativa al personaje o al entorno al recoger un bonus

	friend class Interaccion;
};