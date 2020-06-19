#include "Disparo.h"
#include "glut.h"

Disparo::Disparo() {
	radio = 0.5;
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

float Disparo::GetRadio() {
	return radio;
}

Vector2D Disparo::GetPos() {
	return posicion;
}

void Disparo::SetPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void Disparo::SetVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void Disparo::Inicializa() {
	sprite = new ETSIDI::Sprite(textura, 0, 0, radio * 1.5, radio);
}

void Disparo::Dibuja() {
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	if (velocidad.x < 0)
		sprite->flip(true, false);
	else
		sprite->flip(false, false);
	sprite->draw();	
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}

void Disparo::Mueve(float t) {
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