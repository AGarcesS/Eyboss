#include <sstream>
#include <iostream>
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

		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/texturas/fondo.png").id);
		glDisable(GL_LIGHTING);

		//glTranslatef(0, 0, -0.01); //Se dibuja en un plano un poco por atrás del resto de objetos

		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0); glVertex2f(-15, 10);
		glTexCoord2d(1, 0); glVertex2f(15, 10);
		glTexCoord2d(1, 1); glVertex2f(15, -10);
		glTexCoord2d(0, 1); glVertex2f(-15, -10);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 16);
		ETSIDI::printxy("The Last Chance", -5, 8);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
		ETSIDI::printxy("Pulsa la tecla E para empezar", -5, 7);
		ETSIDI::printxy("Pulsa la tecla S para salir", -5, 6);
		ETSIDI::printxy("Andrea Garcés Sánchez, 53951", -5, 4);
		ETSIDI::printxy("Matías Diego Guichón Gaggiolo, 54000", -5, 3);
		ETSIDI::printxy("Javier Jiménez Wisnes, 54025", -5, 2);
		ETSIDI::printxy("Sandra Rebollo Malvar, 54167", -5, 1);
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
		std::stringstream sstr_tiempo, sstr_bajas;
		std::string str_tiempo, str_bajas;
		int minutos = Global::tiempo / (40 * 60);
		int segundos = (Global::tiempo / 40) - minutos * 60;
		if (segundos > 9)
			sstr_tiempo << "Has tardado " << minutos << ":" << segundos;
		else
			sstr_tiempo << "Has tardado " << minutos << ":0" << segundos;
		str_tiempo = sstr_tiempo.str();
		const char* t_tiempo = str_tiempo.c_str();
		sstr_bajas << "Has eliminado " << Global::bajas << " enemigos";
		str_bajas = sstr_bajas.str();
		const char* t_bajas = str_bajas.c_str();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 16);
		ETSIDI::printxy("ENHORABUENA", -5, 1);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
		ETSIDI::printxy("Has ganado", -5, 0);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
		ETSIDI::printxy(t_tiempo, -5, -2);
		ETSIDI::printxy(t_bajas, -5, -3);
		ETSIDI::printxy("Pulsa la tecla C para continuar", -5, -5);
	}
	else if (estado == GAMEOVER) {
		mundo.Dibuja();
		gluLookAt(mundo.GetOjo().x, mundo.GetOjo().y, 30,
			mundo.GetOjo().x, mundo.GetOjo().y, 0.0,
			0.0, mundo.GetOjo().y, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glTranslatef(mundo.GetOjo().x, mundo.GetOjo().y, 0);
		std::stringstream sstr_tiempo, sstr_bajas;
		std::string str_tiempo, str_bajas;
		int minutos = Global::tiempo / (40 * 60);
		int segundos = (Global::tiempo / 40) - minutos * 60;		
		if (segundos > 9)
			sstr_tiempo << "Has tardado " << minutos << ":" << segundos;
		else
			sstr_tiempo << "Has tardado " << minutos << ":0" << segundos;
		str_tiempo = sstr_tiempo.str();
		const char* t_tiempo = str_tiempo.c_str();
		sstr_bajas << "Has eliminado " << Global::bajas << " enemigos";
		str_bajas = sstr_bajas.str();
		const char* t_bajas = str_bajas.c_str();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 16);
		ETSIDI::printxy("GAMEOVER", -5, 1);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
		ETSIDI::printxy("Has perdido", -5, 0);		
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
		ETSIDI::printxy(t_tiempo, -5, -2);
		ETSIDI::printxy(t_bajas, -5, -3);
		ETSIDI::printxy("Pulsa la tecla C para continuar", -5, -5);
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

		if (Global::cambio_nivel) {
			Global::cambio_nivel = false;
			mundo.CargarNivel();
		}

		if (Global::vida < 0)
			estado = GAMEOVER;
	}	
}