#include "Corazon.h"

void Corazon::Accion(Personaje& p) {
	if (p.GetVida() <= 8) {
		p.SetVida(curacion);
		return;
	}
	if (p.GetVida() < 10) {
		p.SetVida(1);
		return;
	}	
}