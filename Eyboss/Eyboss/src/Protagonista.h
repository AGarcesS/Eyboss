#pragma once
#include "Vector2D.h"

class Protagonista {
private:	
	float altura;
	float ancho;
	float salto; //Potencia de salto
	bool on; //Marca de salto: true-> se puede saltar, false-> no se puede saltar
	bool orientacion; //true-> derecha, false-> izquierda
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	const char* textura;
	int vida;
	bool damage;
	
public:
	Protagonista();
	virtual ~Protagonista() {}

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
	void SetSalto(float sy);
	void SetOn(bool on);
	void SetOrientacion(bool ori);
	void SetVida(int v);
	void SetTextura(const char* text);
	void SetAltura(float alt);

	void Dibuja();
	void Mueve(float t);
	void DestruirContenido();
	void Inicializa();

	friend class Interaccion;
};