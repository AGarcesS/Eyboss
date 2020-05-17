#include "Purk.h"

Purk::Purk() {
	altura = 1.8f;
	ancho = altura;
	posicion.x = 0.0f;
	posicion.y = 10;
	velocidad.x = 3;
	velocidad.y = 0;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	salto = 0;
	on = false;
	orientacion = false;
	vida = 4;
	textura = "bin/texturas/purk.png";
	col = 3;
}

void Purk::Inicializa() {
	purk = new ETSIDI::SpriteSequence(textura, col, 1, 50, true, 0, 0, ancho, altura);
	animacion = purk;
}

void Purk::Dibuja() {
	glTranslatef(posicion.x, posicion.y, 0);
	if (velocidad.x > 0)
		animacion->flip(false, false);
	else if (velocidad.x < 0)
		animacion->flip(true, false);
	animacion->draw();
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void Purk::DestruirContenido() {
	//delete purk;
}