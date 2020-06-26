#include "B_TirachinasLento.h"
#include "Global.h"

B_TirachinasLento::B_TirachinasLento() {
	lado = 0.8;
	textura = "bin/texturas/tirachinasLento.png";
	audio = "bin/sonidos/recogida.wav";
	index = 4;
}

void B_TirachinasLento::Accion(Personaje& p) {
	Global::municionlenta += 2;
}