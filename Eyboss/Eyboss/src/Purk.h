#pragma once
#include "ETSIDI.h"
#include "Personaje.h"

class Purk :public Personaje {
private:
	ETSIDI::SpriteSequence* purk;
public:
	Purk();
	virtual ~Purk() {}

	void Inicializa();
	void Dibuja();
	void DestruirContenido();
};
