#pragma once
#include "ETSIDI.h"
#include "Personaje.h"

class Protagonista :public Personaje {
private:	
	ETSIDI::SpriteSequence* eris;	
public:
	Protagonista();
	virtual ~Protagonista() {}

	void Inicializa();
	void Dibuja();	
	void DestruirContenido();
};