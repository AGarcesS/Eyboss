#pragma once
#include "ETSIDI.h"
#include "Bonus.h"

class Corazon : public Bonus {
private:
	int curacion;
	ETSIDI::Sprite* corazon;
public:
	Corazon();
	virtual ~Corazon() {}
	void Accion(Personaje &p);
};