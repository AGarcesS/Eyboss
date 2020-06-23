#include "Corazon.h"

Corazon::Corazon() {
	curacion = 3;
	lado = 0.8f;
	textura = "bin/texturas/clleno.png";
	audio = "bin/sonidos/vida.wav";
	index = 3;
}

void Corazon::Accion(Personaje& p) {
	if (p.GetVida() <= 8) {
		p.SetVida(2);
		return;
	}
	if (p.GetVida() < 10) {
		p.SetVida(1);
		return;
	}	
}