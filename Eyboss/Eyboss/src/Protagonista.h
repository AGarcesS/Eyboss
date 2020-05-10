#pragma once
#include "Vector2D.h"
#include "Personajes.h"

class Protagonista : public Personajes
{
private:	
	float salto; //Potencia de salto
	bool on; //Marca de salto: true-> se puede saltar, false-> no se puede saltar

	
public:
	Protagonista();
	virtual ~Protagonista() {}

	
	float GetSalto();
	bool GetOn();



	void SetSalto(float sy);
	void SetOn(bool on);


	friend class Interaccion;
};