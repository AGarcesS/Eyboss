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

void Personaje::SetVida(int v) {
	vida = v;
}

void Personaje::Dibuja() {
	glTranslatef(posicion.x, posicion.y, 0);
	if (orientacion)
		animacion->flip(true, false);
	else
		animacion->flip(false, false);
	animacion->draw();
	glTranslatef(-posicion.x, -posicion.y, 0);
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

