#pragma once
#include "Pared.h"

class Caja {
private:	
	Pared suelo;
	Pared techo;
	Pared pared_izq;
	Pared pared_dcha;
	Pared fondo;
public:
	Caja();
	virtual ~Caja() {}

	void Dibuja();
	Pared GetSuelo();
	Pared GetTecho();
	Pared GetPared_Izq();
	Pared GetPared_Dcha();

	friend class Interaccion;
};