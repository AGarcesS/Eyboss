#include "Caja.h"

Caja::Caja() {

	suelo.SetPos(-10.0f, -0.5f, 10.0f, 0.0f);
	techo.SetPos(-10.0f, 15.0f, 10.0f, 15.5f);
	pared_izq.SetPos(-10.5f, 0.0f, -10.0f, 15.0f);
	pared_dcha.SetPos(10.0f, 0.0f, 10.5f, 15.0f);
		
	suelo.SetColor(0, 100, 0);
	techo.SetColor(0, 100, 0);
	pared_dcha.SetColor(0, 150, 0);
	pared_izq.SetColor(0, 150, 0);

	/*suelo.SetTextura("floor.png");
	pared_dcha.SetTextura("wall.png");
	pared_izq.SetTextura("wall.png");
	techo.SetTextura("wall.png");*/
}

void Caja::Dibuja() {
	suelo.Dibuja();
	techo.Dibuja();
	pared_izq.Dibuja();
	pared_dcha.Dibuja();
}

Pared Caja::GetSuelo() {
	return suelo;
}
Pared Caja::GetTecho() {
	return techo;
}
Pared Caja::GetPared_Izq() {
	return pared_izq;
}
Pared Caja::GetPared_Dcha() {
	return pared_dcha;
}