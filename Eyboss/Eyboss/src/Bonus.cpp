#include <stdlib.h>
#include "Bonus.h"
#include "glut.h"

Bonus::Bonus() {
	lado = 1;
	posicion.x = posicion.y = 0;
}

void Bonus::SetPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void Bonus::Dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	sprite->draw();
	glPopMatrix();
}

void Bonus::Audio() {
	ETSIDI::play(audio);
}