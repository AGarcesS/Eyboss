#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "Disparo.h"

class DisparoLento : public Disparo {
public:
	DisparoLento();
	virtual ~DisparoLento() {}

	void Inicializa();


	friend class Interaccion;
};
