#include "B_Tirachinas.h"
#include "Global.h"

B_Tirachinas::B_Tirachinas() {
	lado = 0.8;
	textura = "bin/texturas/tirachinas.png";
	audio = "bin/sonidos/recogida.wav";
	index = 1;
}

void B_Tirachinas::Accion(Personaje &p) {
	Global::municion += 5;
}