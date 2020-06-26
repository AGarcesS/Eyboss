#pragma once
#include "Personaje.h"

class Protagonista :public Personaje {
public:
	Protagonista():Personaje(Personaje::PROTAGONISTA) {
		altura = 1.8f;
		ancho = altura;
		posicion.x = 0.0f;
		posicion.y = altura / 2;
		velocidad.x = velocidad.y = 0;
		aceleracion.x = 0.0f;
		aceleracion.y = -9.8f;
		salto = 8.0f;
		on = false;
		orientacion = false;
		nogancho = true;
		vida = 10;
		textura = "bin/texturas/eris_der2.png";
		col = 6;
	}
	virtual ~Protagonista() {}

	void Dibuja();	
	void ResetVida();
};