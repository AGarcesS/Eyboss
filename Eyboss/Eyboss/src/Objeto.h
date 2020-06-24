#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"
#include "ListaEnemigos.h"
#include "ListaPlataformas.h"
#include "Personaje.h"

class Objeto {
public:
	enum objetos { OBJETO = 0, TIRACHINAS, ESPADA, TIRACHINAS_LENTO, TIRACHINAS_RAPIDO };
protected:
	objetos tipo;
	float ancho;
	float altura;
	Vector2D posicion;
	bool orientacion;		//marca de orientacion
	ETSIDI::Sprite* sprite;
	const char* textura;
public:
	Objeto(objetos t = OBJETO) :tipo(t) {}
	virtual ~Objeto() {}

	objetos GetTipo() { return tipo; }

	int index;

	virtual void Dibuja() {}
	virtual void Inicializa() {}
	virtual void Mueve(float t) {}
	virtual void DestruirContenido() {}
	virtual void Ataca(Personaje& p) {}
	virtual void Colision(ListaEnemigos& p) {}
	virtual void Colision(ListaPlataformas& p) {}
	virtual void Colision(Caja& c) {}
};