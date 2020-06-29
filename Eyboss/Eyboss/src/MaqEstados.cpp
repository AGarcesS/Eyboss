#include "MaqEstados.h"
#include "ETSIDI.h"
#include "glut.h"
#include "Global.h"

MaqEstados::MaqEstados() {
	estado = INICIO;
}

void MaqEstados::Dibuja() {
	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 16);
		ETSIDI::printxy("Titulo", -5, 8);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
		ETSIDI::printxy("Pulsa la tecla E para empezar", -5, 7);
		ETSIDI::printxy("Pulsa la tecla S para salir", -5, 6);
	}
	else if (estado == JUEGO) {
		mundo.Dibuja();
	}

	else if (estado == FIN) {
		mundo.Dibuja();
		gluLookAt(mundo.GetOjo().x, mundo.GetOjo().y, 30,
			mundo.GetOjo().x, mundo.GetOjo().y, 0.0,
			0.0, mundo.GetOjo().y, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glTranslatef(mundo.GetOjo().x, mundo.GetOjo().y, 0);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 16);
		ETSIDI::printxy("ENHORABUENA", -5, 1);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
		ETSIDI::printxy("Has ganado", -5, 0);
		ETSIDI::printxy("Pulsa la tecla C para continuar", -5, -1);
	}
	else if (estado == GAMEOVER) {
		mundo.Dibuja();
		gluLookAt(mundo.GetOjo().x, mundo.GetOjo().y, 30,
			mundo.GetOjo().x, mundo.GetOjo().y, 0.0,
			0.0, mundo.GetOjo().y, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glTranslatef(mundo.GetOjo().x, mundo.GetOjo().y, 0);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 16);
		ETSIDI::printxy("GAMEOVER", -5, 1);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
		ETSIDI::printxy("Has perdido", -5, 0);
		ETSIDI::printxy("Pulsa la tecla C para continuar", -5, -1);
	}
	else if (estado == PAUSA) {
		mundo.Dibuja();
		gluLookAt(mundo.GetOjo().x, mundo.GetOjo().y, 30,
			mundo.GetOjo().x, mundo.GetOjo().y, 0.0, 
			0.0, mundo.GetOjo().y, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glTranslatef(mundo.GetOjo().x, mundo.GetOjo().y, 0);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 16);
		ETSIDI::printxy("PAUSA", -5, 1);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
		ETSIDI::printxy("Pulsa la tecla C para volver al juego", -5, 0);
		ETSIDI::printxy("Pulsa la tecla S para volver a inicio", -5, -1);
	}
}

void MaqEstados::Tecla(unsigned char key) {
	if (estado == INICIO) {
		if (key == 'e') {
			mundo.Inicializa();
			estado = JUEGO;
		}
		if (key == 's') {
			exit(0);
		}
	}
	else if (estado == JUEGO) {
		mundo.Tecla(key);
		if (key == 'p')
			estado = PAUSA;
	}
	else if (estado == FIN) {
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == GAMEOVER) {
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == PAUSA) {
		if (key == 'c')
			estado = JUEGO;
		if (key == 's')
			estado = INICIO;
	}
}

void MaqEstados::TeclaEspecial(unsigned char key) {
	if (estado == JUEGO) {
		mundo.TeclaEspecial(key);
	}	
}

void MaqEstados::TeclaMantenida(unsigned char key) {
	if (estado == JUEGO) {
		mundo.TeclaMantenida(key);
	}	
}

void MaqEstados::Mueve() {
	if (estado == JUEGO) {
		mundo.Mueve();
		/*if ((Global::tiempo / 40) > 30) {
			estado = FIN;
		}*/

		if (Global::vida < 0)
			estado = GAMEOVER;
	}	
}