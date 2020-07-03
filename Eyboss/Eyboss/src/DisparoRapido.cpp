#include "DisparoRapido.h"
#include "glut.h"


void DisparoRapido::Inicializa() {
	sprite = new ETSIDI::Sprite(textura, 0, 0, radio * 1.5, radio);
}