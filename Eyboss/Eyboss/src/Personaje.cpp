#include <math.h>
#include "Personaje.h"
#include "glut.h"

Vector2D Personaje::GetPos() {
	return posicion;
}

Vector2D Personaje::GetVel() {
	return velocidad;
}

Vector2D Personaje::GetVelIni() {
	return vel_ini;
}

Vector2D Personaje::GetAcel() {
	return aceleracion;
}

float Personaje::GetAltura() {
	return altura;
}

float Personaje::GetAncho() {
	return ancho;
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

bool Personaje::GetOrienini() {
	return orien_ini;
}

int Personaje::GetVida() {
	return vida;
}

int Personaje::GetDaño() {
	return daño;
}

int Personaje::GetAtaque() {
	return señal_ataque;
}

void Personaje::SetPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void Personaje::SetVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void Personaje::SetVelIni(float vix, float viy) {
	velocidad.x = vel_ini.x = vix;
	velocidad.y = vel_ini.y = viy;
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

void Personaje::SetOrienini(bool oriini) {
	orientacion = orien_ini = oriini;
}

void Personaje::SetTextura(const char* t) {
	textura = t;
}

void Personaje::SetVida(int v) {
	vida += v;
	if (v < 0 && this->GetTipo() == PROTAGONISTA)
		ETSIDI::play("bin/sonidos/damage.wav");
}

void Personaje::SetAtaque(int a) {
	señal_ataque = a;
}

void Personaje::Dibuja() {
	glTranslatef(posicion.x, posicion.y, 0);
	if (velocidad.x < 0)
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

void Personaje::Inicializa() {
	animacion = new ETSIDI::SpriteSequence(textura, col, 1, 50, true, 0, 0, ancho, altura, 0);
}

