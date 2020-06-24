#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"

class Personaje {
public:
	enum enemigos { PURK, VELOZ, TROLL };
protected:
	enemigos tipo;
	float altura;                                  
	float ancho;
	bool orientacion; //marca de orientacion
	bool orien_ini;
	bool on; //marca de salto
	float salto; //potencia de salto
	Vector2D posicion;                             
	Vector2D velocidad;
	Vector2D vel_ini;
	Vector2D aceleracion;
	const char* textura;
	int vida;	 
	int col;
	ETSIDI::SpriteSequence* animacion;                //Sprites

public:
	Personaje() {}
	enemigos GetTipo() { return tipo; }
	virtual ~Personaje() {}

	Vector2D GetPos();
	Vector2D GetVel();
	Vector2D GetVelIni();
	Vector2D GetAcel();
	float GetAltura();
	float GetAncho();
	float GetSalto();
	bool GetOn();
	bool GetOrientacion();
	bool GetOrienini();
	int GetVida();
	virtual void GetDamage() {} //Depende de cada enemigo (para el protagonista depende del objeto)

	void SetPos(float px, float py);
	void SetVel(float vx, float vy);
	void SetVelIni(float vix, float viy);
	void SetAcel(float ax, float ay);
	void SetSalto(float s);
	void SetOn(bool x);
	void SetOrientacion(bool ori);
	void SetOrienini(bool oriini);
	void SetVida(int v);

	void SetTextura(const char* t);

	virtual void Dibuja();
	void Mueve(float t);
	void Inicializa();

	friend class Interaccion;
};