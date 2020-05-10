#include<math.h>
#include "ETSIDI.h"
#include "Protagonista.h"
#include "glut.h"

Protagonista::Protagonista() {
	altura = 1.8f;
	ancho = 1.0f;
	posicion.x = 0.0f;
	posicion.y = altura / 2;
	velocidad.x = velocidad.y = 0;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	salto = 8.0f;
	on = false;
	orientacion = false;
}


float Protagonista::GetSalto() {
	return salto;
}

bool Protagonista::GetOn() {
	return on;
}



void Protagonista::SetSalto(float sy) {
	salto = sy;
}

void Protagonista::SetOn(bool x) {
	on = x;
}
