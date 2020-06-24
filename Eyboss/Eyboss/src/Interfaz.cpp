#include <sstream>
#include "Interfaz.h"
#include "Global.h"
#include "glut.h"

void Interfaz::ImprimeJuego(Protagonista &p) {
	std::stringstream sstr_tiempo, sstr_vida, sstr_bajas, sstr_municion, sstr_municionlenta, sstr_municionrapida;
	std::string str_tiempo, str_vida, str_bajas, str_municion, str_municionlenta, str_municionrapida;

	glTranslatef(p.GetPos().x, p.GetPos().y, 1);

	int minutos, segundos;

	minutos = Global::tiempo / (40 * 60); //Cada 25 ms se incrementa en uno, por lo que para milisegundos se divide entre 40
	segundos = (Global::tiempo / 40) - minutos * 60;

	if (segundos > 9)
		sstr_tiempo << "Tiempo: " << minutos << ":" << segundos;
	else
		sstr_tiempo << "Tiempo: " << minutos << ":0" << segundos;

	str_tiempo = sstr_tiempo.str();
	const char* t_tiempo = str_tiempo.c_str();
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
	ETSIDI::printxy(t_tiempo, -14, 10);

	sstr_vida << "Vida: " << p.GetVida();
	str_vida = sstr_vida.str();
	const char* t_vida = str_vida.c_str();
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
	ETSIDI::printxy(t_vida, -14, 9);

	sstr_bajas << "Kills: " << Global::bajas;
	str_bajas = sstr_bajas.str();
	const char* t_bajas = str_bajas.c_str();
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
	ETSIDI::printxy(t_bajas, -14, 8);

	sstr_municion << "Normal: " << Global::municion;
	str_municion = sstr_municion.str();
	const char* t_municion = str_municion.c_str();
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
	ETSIDI::printxy(t_municion, -14, 7);

	sstr_municionlenta << "Lenta: " << Global::municionlenta;
	str_municionlenta = sstr_municionlenta.str();
	const char* t_municionlenta = str_municionlenta.c_str();
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
	ETSIDI::printxy(t_municionlenta, -14, 6);

	sstr_municionrapida << "Rapida: " << Global::municionrapida;
	str_municionrapida = sstr_municionrapida.str();
	const char* t_municionrapida = str_municionrapida.c_str();
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
	ETSIDI::printxy(t_municionrapida, -14, 5);

	glPushMatrix();
	corazon->draw();
	glPopMatrix();
}

void Interfaz::Inicializa() {
	corazon = new ETSIDI::Sprite("bin/texturas/clleno.png", -11.1, 9.1, 0.8, 0.8);
}