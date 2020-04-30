#include<math.h>
#include "ETSIDI.h"
#include "Protagonista.h"
#include "glut.h"

Protagonista::Protagonista() {
	altura = 1.8f;
	ancho = 1.0f;
	posicion.x = 0.0f;
	posicion.y = altura / 2;
	velocidad.x = velocidad.y = 0;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	salto = 8.0f;
	on = false;
	orientacion = false;
}

Vector2D Protagonista::GetPos() {
	return posicion;
}

Vector2D Protagonista::GetVel() {
	return velocidad;
}

float Protagonista::GetAltura() {
	return altura;
}

Vector2D Protagonista::GetAcel() {
	return aceleracion;
}

float Protagonista::GetSalto() {
	return salto;
}

bool Protagonista::GetOn() {
	return on;
}

bool Protagonista::GetOrientacion() {
	return orientacion;
}

void Protagonista::SetPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void Protagonista::SetVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void Protagonista::SetAcel(float ax, float ay) {
	aceleracion.x = ax;
	aceleracion.y = ay;
}

void Protagonista::SetSalto(float sy) {
	salto = sy;
}

void Protagonista::SetOn(bool x) {
	on = x;
}

void Protagonista::SetOrientacion(bool ori) {
	orientacion = ori;
}

void Protagonista::Dibuja() {

	/*glEnable(GL_TEXTURE_2D);                                                    //Texturas
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("pers.png").id);
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1, 1, 1);
	glRectd(-ancho / 2, -altura / 2, ancho / 2, altura / 2);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();*/

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectd(-ancho/2, -altura/2, ancho/2, altura/2);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}

void Protagonista::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5 * t * t);
	velocidad = velocidad + aceleracion * t;
}