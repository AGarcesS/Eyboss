#pragma once
#include "Personaje.h"

class Protagonista :public Personaje {
public:
	Protagonista():Personaje(Personaje::PROTAGONISTA, 1.8f, 1.8f, false, false, false, 8.0f, "bin/texturas/eris_der2.png", 10, 6, true, false, false, false, 0) {
//		altura = 1.8f;
//		ancho = altura;
		posicion.x = 0.0f;
		posicion.y = altura / 2;
		velocidad.x = velocidad.y = 0;
		aceleracion.x = 0.0f;
		aceleracion.y = -9.8f;
//		salto = 8.0f;
//		on = false;
//		orientacion = false;
//		nogancho = true;
//		m_daño = false;
//		m_tiempo = false;
//		m_parpadeo = false;
//		vida = 10;
//		textura = "bin/texturas/eris_der2.png";
//		col = 6;
	}


	virtual ~Protagonista() {}

	void Dibuja();	
	void Reset();
};