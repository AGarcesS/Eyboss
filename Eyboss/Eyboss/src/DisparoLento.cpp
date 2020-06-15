#include "DisparoLento.h"
#include "glut.h"

DisparoLento::DisparoLento() {
	radio = 0.5;
	posicion.x = 0;
	posicion.y = 0;
	velocidad.x = 5;
	velocidad.y = 0;
	aceleracion.x = 0;
	aceleracion.y = 0;
	origen.x = 0;
	origen.y = 0;
	longitud = 0;
	textura = "bin/texturas/bolitahada.png";
}


void DisparoLento::Inicializa() {
	sprite = new ETSIDI::Sprite(textura, 0, 0, radio * 1.5, radio);
}

void DisparoLento::Dibuja() {
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	if (velocidad.x < 0)
		sprite->flip(true, false);
	else
		sprite->flip(false, false);
	sprite->draw();
	glPopMatrix();
}

void DisparoLento::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5 * t * t);
	velocidad = velocidad + aceleracion * t;


	if (velocidad.x > 0) {
		origen = origen - velocidad * t;
		if (origen.x < -longitud)
			origen.x = -longitud;
	}
	else if (velocidad.x < 0) {
		origen = origen - velocidad * t;
		if (origen.x > longitud)
			origen.x = longitud;
	}
}