#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"

class Personaje {
protected:
	float altura;                                  
	float ancho;
	bool orientacion; //marca de orientacion
	bool on; //marca de salto
	float salto; //potencia de salto
	Vector2D posicion;                             
	Vector2D velocidad;
	Vector2D aceleracion;
	const char* textura;
	int vida;	 
	int col;
	ETSIDI::SpriteSequence* animacion;                //Sprites

public:
	Personaje() {}
	virtual ~Personaje() {}

	Vector2D GetPos();
	Vector2D GetVel();
	Vector2D GetAcel();
	float GetAltura();
	float GetSalto();
	bool GetOn();
	bool GetOrientacion();
	int GetVida();

	void SetPos(float px, float py);
	void SetVel(float vx, float vy);
	void SetAcel(float ax, float ay);
	void SetSalto(float s);
	void SetOn(bool x);
	void SetOrientacion(bool ori);
	void SetVida(int v);

	virtual void Dibuja();
	void Mueve(float t);
	virtual void Inicializa() {}
	virtual void DestruirContenido() {}

	friend class Interaccion;
};