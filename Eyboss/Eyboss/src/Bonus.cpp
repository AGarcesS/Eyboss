#include <stdlib.h>
#include "Bonus.h"
#include "glut.h"

Bonus::Bonus() {
	lado = 1;
	posicion.x = posicion.y = 0;
	velocidad.x = velocidad.y = 0;
	aceleracion.x = aceleracion.y = 0;
}

void Bonus::SetPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void Bonus::Dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	glutSolidCube(lado);
	glPopMatrix();
}

void Bonus::Mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * 0.5 * t * t;
	velocidad = velocidad + aceleracion * t;
}