#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "Disparo.h"

class DisparoRapido : public Disparo {
public:
	DisparoRapido();
	virtual ~DisparoRapido() {}

	void Inicializa();
	void Dibuja();
	void Mueve(float t);

	friend class Interaccion;
};
