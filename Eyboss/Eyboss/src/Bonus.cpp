#include "Bonus.h"
#include "glut.h"

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

void Bonus::Inicializa() {
	sprite = new ETSIDI::Sprite(textura, 0, 0, lado, lado);
}