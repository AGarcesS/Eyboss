#pragma once
#include "ETSIDI.h"
#include "Tiempo.h"
#include "Protagonista.h"

class Interfaz {
private:
	ETSIDI::Sprite* corazon;
public:
	void ImprimeJuego(Protagonista p, Tiempo t);
	void Inicializa();
	void DestruirContenido();
};