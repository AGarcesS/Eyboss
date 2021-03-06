#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"

class Disparo {
protected:	
	float radio; 
	float longitud; //longitud del disparo (solo para disparo gancho)
	int damage; //da�o que provoca el disparo
	float rapidez; //velocidad del disparo
	Vector2D origen;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	ETSIDI::Sprite* sprite;
	const char* textura;
public:
	Disparo() {
		radio = 0.5;
		damage = 2;
		rapidez = 7.0f;
		posicion.x = 0;
		posicion.y = 0;
		velocidad.x = 6;
		velocidad.y = 0;
		aceleracion.x = 0;
		aceleracion.y = 0;
		origen.x = 0;
		origen.y = 0;
		longitud = 0;
		textura = "bin/texturas/bolitahada.png";
	}
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