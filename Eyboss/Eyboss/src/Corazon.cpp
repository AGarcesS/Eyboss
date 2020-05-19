#include "Corazon.h"

Corazon::Corazon() {
	lado = 0.8f;
	textura = "bin/texturas/clleno.png";
	audio = "bin/sonidos/vida.wav";
}

void Corazon::Inicializa() {
	corazon = new ETSIDI::Sprite(textura, 0, 0, lado, lado);
	sprite = corazon;
}

void Corazon::DestruirContenido() {
	//delete corazon;
}