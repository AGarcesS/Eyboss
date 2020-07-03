#include "DisparoLento.h"
#include "glut.h"

void DisparoLento::Inicializa() {
	sprite = new ETSIDI::Sprite(textura, 0, 0, radio * 1.5, radio);
}