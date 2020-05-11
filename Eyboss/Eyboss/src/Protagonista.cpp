#include<math.h>
#include "ETSIDI.h"
#include "Protagonista.h"
#include "glut.h"

ETSIDI::SpriteSequence* animacion_par;

Protagonista::Protagonista() {
	altura = 1.8f;
	ancho = altura;
	posicion.x = 0.0f;
	posicion.y = altura / 2;
	velocidad.x = velocidad.y = 0;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	salto = 8.0f;
	on = false;
	orientacion = false;
	vida = 10;
	damage = false;
	textura = "bin/texturas/eris_der.png";
}

void Protagonista::Inicializa() {
	animacion_par = new ETSIDI::SpriteSequence(textura, 6, 1, 50, true, 0, 0, altura, altura);
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

int Protagonista::GetVida() {
	return vida;
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

void Protagonista::SetVida(int v) {
	vida = v;
}

void Protagonista::SetTextura(const char* text) {
	textura = text;
}

void Protagonista::SetAltura(float alt) {
	altura = alt;
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

	/*glPushMatrix();                                                            //Rectangulo
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectd(-ancho/2, -altura/2, ancho/2, altura/2);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();*/

	glTranslatef(posicion.x, posicion.y, 0);
	if (velocidad.x > 0)
		animacion_par->flip(true, false);
	else if (velocidad.x < 0)
		animacion_par->flip(false, false);
	animacion_par->draw();
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void Protagonista::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * (0.5 * t * t);
	velocidad = velocidad + aceleracion * t;

	if (velocidad.x > 0) {
		animacion_par->pause(false);
	}
	else if (velocidad.x < 0) {
		animacion_par->pause(false);
	}
	else if (velocidad.x == 0) {
		animacion_par->setState(5, true);
	}
	animacion_par->loop();
}

void Protagonista::DestruirContenido() {
	//delete animacion_par;
}