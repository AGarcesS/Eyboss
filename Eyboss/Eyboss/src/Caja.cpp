#include "Caja.h"
#include "glut.h"

Caja::Caja() {

	suelo.SetPos(-10.0f, -0.5f, 80.0f, 0.0f);
	techo.SetPos(-10.0f, 15.0f, 80.0f, 15.5f);
	pared_izq.SetPos(-10.5f, 0.0f, -10.0f, 15.0f);
	pared_dcha.SetPos(80.0f, 0.0f, 80.5f, 15.0f);

	fondo.SetZ(-0.1);
	fondo.SetPos(-10.5, 15, 80, 0);
	fondo.SetTextura("bin/texturas/fondo.png");
		
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
	fondo.Dibuja(0.05);
	suelo.Dibuja(0.1);
	techo.Dibuja(0.1);
	pared_izq.Dibuja(0.1);
	pared_dcha.Dibuja(0.1);
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