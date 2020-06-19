#include <math.h>
#include "Personaje.h"
#include "glut.h"

Vector2D Personaje::GetPos() {
	return posicion;
}

Vector2D Personaje::GetVel() {
	return velocidad;
}

Vector2D Personaje::GetAcel() {
	return aceleracion;
}

float Personaje::GetAltura() {
	return altura;
}

float Personaje::GetSalto() {
	return salto;
}

bool Personaje::GetOn() {
	return on;
}

bool Personaje::GetOrientacion() {
	return orientacion;
}

int Personaje::GetVida() {
	return vida;
}

void Personaje::SetPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void Personaje::SetVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void Personaje::SetAcel(float ax, float ay) {
	aceleracion.x = ax;
	aceleracion.y = ay;
}

void Personaje::SetSalto(float s) {
	salto = s;
}

void Personaje::SetOn(bool x) {
	on = x;
}

void Personaje::SetOrientacion(bool ori) {
	orientacion = ori;
}

void Personaje::SetTextura(const char* t) {
	textura = t;
}

void Personaje::SetVida(int v) {
	vida += v;
}

void Personaje::Dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	if (velocidad.x < 0)
		animacion->flip(true, false);
	else
		animacion->flip(false, false);
	animacion->draw();
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}

void Personaje::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5 * t * t);
	velocidad = velocidad + aceleracion * t;

	if (velocidad.x != 0)
		animacion->pause(false);
	else
		animacion->setState(0, true);
	animacion->loop();		
}

void Personaje::Inicializa() {
	animacion = new ETSIDI::SpriteSequence(textura, col, 1, 50, true, 0, 0, ancho, altura, 0);
}

