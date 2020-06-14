#pragma once
#include "Personaje.h"

class Purk :public Personaje {
private:
	static int bajas;
public:
	Purk();
	virtual ~Purk() {}
};
