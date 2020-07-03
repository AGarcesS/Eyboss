#include "Disparo.h"
#include "glut.h"

float Disparo::GetRadio() {
	return radio;
}

int Disparo::GetDamage() {
	return damage;
}

float Disparo::GetRapidez() {
	return rapidez;
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
	glPopMatrix();
}

void Disparo::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5 * t * t);
	velocidad = velocidad + aceleracion * t;
}