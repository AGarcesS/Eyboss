#include "B_TirachinasRapido.h"
#include "Global.h"

B_TirachinasRapido::B_TirachinasRapido() {
	lado = 0.8;
	textura = "bin/texturas/tirachinasRapido.png";
	audio = "bin/sonidos/recogida.wav";
	index = 5;
}

void B_TirachinasRapido::Accion(Personaje& p) {
	Global::municionrapida += 2;
}