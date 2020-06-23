#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "Disparo.h"

class DisparoRapido : public Disparo {
public:
	DisparoRapido();
	virtual ~DisparoRapido() {}

	void Inicializa();


	friend class Interaccion;
};
