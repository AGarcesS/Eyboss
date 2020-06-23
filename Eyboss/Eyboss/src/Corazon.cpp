#include "Corazon.h"

Corazon::Corazon() {
	curacion = 3;
	lado = 0.8f;
	textura = "bin/texturas/clleno.png";
	audio = "bin/sonidos/vida.wav";
	index = 3;
}

void Corazon::Accion(Personaje& p) {
	p.SetVida(2);
}