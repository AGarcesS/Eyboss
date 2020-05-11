#include "Tiempo.h"
#include "Mundo.h"

Tiempo::Tiempo() {
	tiempo = 0;
	reset = false;
}

float Tiempo::GetTiempo() {
	return tiempo;
}

bool Tiempo::GetReset() {
	return reset;
}

void Tiempo::SetTiempo(float t) {
	tiempo = t / 40;
}

void Tiempo::SetReset(bool r) {
	reset = r;
}