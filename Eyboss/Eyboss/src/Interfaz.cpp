#include <sstream>
#include "Interfaz.h"
#include "glut.h"

void Interfaz::ImprimeJuego(Protagonista p, Tiempo t) {
	std::stringstream sstr_tiempo, sstr_vida;
	std::string str_tiempo, str_vida;

	glTranslatef(p.GetPos().x, p.GetPos().y, 1);

	int minutos, segundos;
	minutos = t.GetTiempo() / 60;
	segundos = t.GetTiempo() - minutos * 60;

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

	corazon->draw();
}

void Interfaz::Inicializa() {
	corazon = new ETSIDI::Sprite("bin/texturas/clleno.png", -11, 9.2, 0.8, 0.8);
}

void Interfaz::DestruirContenido() {
	//delete corazon;
}