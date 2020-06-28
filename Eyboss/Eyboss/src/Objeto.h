#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"
#include "ListaEnemigos.h"
#include "ListaPlataformas.h"
#include "Personaje.h"

class Objeto {
public:
	enum objetos { OBJETO = 0, TIRACHINAS, ESPADA, TIRACHINAS_LENTO, TIRACHINAS_RAPIDO, GANCHO };
protected:
	objetos tipo;
	float ancho;
	float altura;
	Vector2D posicion;
	bool orientacion;		//marca de orientacion
	float tiempo0;
	bool m_tiempo;
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
	virtual void Seguir(Personaje& p) {}
	virtual void DestruirContenido() {}
	virtual void Ataca(Personaje& p) {}
	virtual void Colision(Personaje& p) {}
	virtual void Colision(ListaEnemigos& p) {}
	virtual void Colision(ListaPlataformas& p, Personaje* pe = NULL) {}
};