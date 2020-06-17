#include "DisparoRapido.h"
#include "glut.h"

DisparoRapido::DisparoRapido() {
	radio = 0.5;
	posicion.x = 0;
	posicion.y = 0;
	velocidad.x = 10;
	velocidad.y = 0;
	aceleracion.x = 0;
	aceleracion.y = 0;
	origen.x = 0;
	origen.y = 0;
	longitud = 0;
	textura = "bin/texturas/rapido.png";
}


void DisparoRapido::Inicializa() {
	sprite = new ETSIDI::Sprite(textura, 0, 0, radio * 1.5, radio);
}