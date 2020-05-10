#include "Personajes.h"
#include "glut.h"

Vector2D Personajes::GetPos() {
	return posicion;
}

Vector2D Personajes::GetVel() {
	return velocidad;
}

float Personajes::GetAltura() {
	return altura;
}

Vector2D Personajes::GetAcel() {
	return aceleracion;
}

bool Personajes::GetOrientacion() {
	return orientacion;
}

void Personajes::SetPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void Personajes::SetVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void Personajes::SetAcel(float ax, float ay) {
	aceleracion.x = ax;
	aceleracion.y = ay;
}

void Personajes::SetOrientacion(bool ori) {
	orientacion = ori;
}

void Personajes::Dibuja() {

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
	glRectd(-ancho / 2, -altura / 2, ancho / 2, altura / 2);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}

void Personajes::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5 * t * t);
	velocidad = velocidad + aceleracion * t;
}