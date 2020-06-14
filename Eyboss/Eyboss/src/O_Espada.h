#pragma once
#include "ETSIDI.h"
#include "Objeto.h"
#include "Personaje.h"

class O_Espada:public Objeto {
private:
	ETSIDI::Sprite* espada;
public:
	O_Espada() :Objeto(ESPADA) {}
	virtual ~O_Espada() {}
};