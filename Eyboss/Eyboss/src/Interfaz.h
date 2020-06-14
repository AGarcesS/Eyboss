#pragma once
#include "ETSIDI.h"
#include "Protagonista.h"

class Interfaz {
private:
	ETSIDI::Sprite* corazon;
public:
	void ImprimeJuego(Protagonista &p);
	void Inicializa();
};