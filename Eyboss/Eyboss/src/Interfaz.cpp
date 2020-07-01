#include <sstream>
#include "Interfaz.h"
#include "Global.h"
#include "glut.h"

void Interfaz::ImprimeJuego(Protagonista& p, ListaObjetos& l) {
	std::stringstream sstr_tiempo, sstr_vida, sstr_bajas, sstr_municion, sstr_municionlenta, sstr_municionrapida;
	std::string str_tiempo, str_vida, str_bajas, str_municion, str_municionlenta, str_municionrapida;

	bool m1 = false, m2 = false, m3 = false, m4 = false, m5 = false;	

	glPushMatrix();
	glTranslatef(p.GetPos().x, p.GetPos().y, 0.9);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/texturas/wood1.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(-13.5, -7);
	glTexCoord2d(1, 1); glVertex2f(-7.5, -7);
	glTexCoord2d(1, 0); glVertex2f(-7.5, -11);
	glTexCoord2d(0, 0); glVertex2f(-13.5, -11);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(p.GetPos().x, p.GetPos().y, 0.9);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/texturas/wood1.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(7.5, -7);
	glTexCoord2d(1, 1); glVertex2f(13.5, -7);
	glTexCoord2d(1, 0); glVertex2f(13.5, -11);
	glTexCoord2d(0, 0); glVertex2f(7.5, -11);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();	

	for (int i = 0; i < ListaObjetos::n_objetos; i++) {
		if (l[i] != 0) {
			if (l[i]->GetTipo() == Objeto::TIRACHINAS) {
				m1 = true;
			}

			if (l[i]->GetTipo() == Objeto::TIRACHINAS_LENTO) {
				m2 = true;
			}

			if (l[i]->GetTipo() == Objeto::TIRACHINAS_RAPIDO) {
				m3 = true;
			}

			if (l[i]->GetTipo() == Objeto::ESPADA) {
				m4 = true;
			}

			if (l[i]->GetTipo() == Objeto::GANCHO) {
				m5 = true;
			}

		}
	}

	if (m1 || m2 || m3 || m4 || m5) {
		glPushMatrix();
		glTranslatef(p.GetPos().x, p.GetPos().y, 0.9);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/texturas/wood1.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2f(-5, -7);
		glTexCoord2d(1, 1); glVertex2f(5, -7);
		glTexCoord2d(1, 0); glVertex2f(5, -11);
		glTexCoord2d(0, 0); glVertex2f(-5, -11);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	glTranslatef(p.GetPos().x, p.GetPos().y, 1);

	if (m1) {
		sstr_municion << Global::municion;
		str_municion = sstr_municion.str();
		const char* t_municion = str_municion.c_str();
		tirachinas->draw();
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
		ETSIDI::printxy(t_municion, -4, -8.5);
		ETSIDI::printxy("Q", -4, -10);
	}

	if (m2) {
		sstr_municionlenta << Global::municionlenta;
		str_municionlenta = sstr_municionlenta.str();
		const char* t_municionlenta = str_municionlenta.c_str();
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
		ETSIDI::printxy(t_municionlenta, -2, -8.5);
		ETSIDI::printxy("W", -2, -10);
		tirachinas_lento->draw();
	}

	if (m3) {
		sstr_municionrapida << Global::municionrapida;
		str_municionrapida = sstr_municionrapida.str();
		const char* t_municionrapida = str_municionrapida.c_str();
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
		ETSIDI::printxy(t_municionrapida, 0, -8.5);
		ETSIDI::printxy("E", 0, -10);
		tirachinas_rapido->draw();
	}

	if (m4) {
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
		ETSIDI::printxy("R", 2, -10);
		espada->draw();
	}

	if (m5) {
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
		ETSIDI::printxy("T", 4, -10);
		gancho->draw();
	}

	int minutos = Global::tiempo / (40 * 60); //Cada 25 ms se incrementa en uno, por lo que para milisegundos se divide entre 40
	int segundos = (Global::tiempo / 40) - minutos * 60;

	if (segundos > 9)
		sstr_tiempo << minutos << ":" << segundos;
	else
		sstr_tiempo << minutos << ":0" << segundos;

	str_tiempo = sstr_tiempo.str();
	const char* t_tiempo = str_tiempo.c_str();
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
	ETSIDI::printxy(t_tiempo, -12, -8);
	tiempo->draw();	

	switch (p.GetVida()) {

	case 10:
	{
		corazon1->draw(); corazon2->draw(); corazon3->draw(); corazon4->draw(); corazon5->draw();
		break;
	}
	case 9:
	{
		corazon1->draw(); corazon2->draw(); corazon3->draw(); corazon4->draw(); corazon_m5->draw();
		break;
	}
	case 8:
	{
		corazon1->draw(); corazon2->draw(); corazon3->draw(); corazon4->draw(); corazon_v5->draw();
		break;
	}
	case 7:
	{
		corazon1->draw(); corazon2->draw(); corazon3->draw(); corazon_m4->draw(); corazon_v5->draw();
		break;
	}
	case 6:
	{
		corazon1->draw(); corazon2->draw(); corazon3->draw(); corazon_v4->draw(); corazon_v5->draw();
		break;
	}
	case 5:
	{
		corazon1->draw(); corazon2->draw(); corazon_m3->draw(); corazon_v4->draw(); corazon_v5->draw();
		break;
	}
	case 4:
	{
		corazon1->draw(); corazon2->draw(); corazon_v3->draw(); corazon_v4->draw(); corazon_v5->draw();
		break;
	}
	case 3:
	{
		corazon1->draw(); corazon_m2->draw(); corazon_v3->draw(); corazon_v4->draw(); corazon_v5->draw();
		break;
	}
	case 2:
	{
		corazon1->draw(); corazon_v2->draw(); corazon_v3->draw(); corazon_v4->draw(); corazon_v5->draw();
		break;
	}
	case 1:
	{
		corazon_m1->draw(); corazon_v2->draw(); corazon_v3->draw(); corazon_v4->draw(); corazon_v5->draw();
		break;
	}
	case 0:
	{
		corazon_v1->draw(); corazon_v2->draw(); corazon_v3->draw(); corazon_v4->draw(); corazon_v5->draw();
		break;
	}
	}

	sstr_bajas << Global::bajas;
	str_bajas = sstr_bajas.str();
	const char* t_bajas = str_bajas.c_str();
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("bin/fuentes/fuente.ttf", 12);
	ETSIDI::printxy(t_bajas, 10, -8);
	bajas->draw();
}

void Interfaz::Inicializa() {
	corazon1 = new ETSIDI::Sprite("bin/texturas/clleno.png", -12.5, -9, 0.8, 0.8);
	corazon2 = new ETSIDI::Sprite("bin/texturas/clleno.png", -11.5, -9, 0.8, 0.8);
	corazon3 = new ETSIDI::Sprite("bin/texturas/clleno.png", -10.5, -9, 0.8, 0.8);
	corazon4 = new ETSIDI::Sprite("bin/texturas/clleno.png", -9.5, -9, 0.8, 0.8);
	corazon5 = new ETSIDI::Sprite("bin/texturas/clleno.png", -8.5, -9, 0.8, 0.8);

	corazon_v1 = new ETSIDI::Sprite("bin/texturas/cvacio.png", -12.5, -9, 0.8, 0.8);
	corazon_v2 = new ETSIDI::Sprite("bin/texturas/cvacio.png", -11.5, -9, 0.8, 0.8);
	corazon_v3 = new ETSIDI::Sprite("bin/texturas/cvacio.png", -10.5, -9, 0.8, 0.8);
	corazon_v4 = new ETSIDI::Sprite("bin/texturas/cvacio.png", -9.5, -9, 0.8, 0.8);
	corazon_v5 = new ETSIDI::Sprite("bin/texturas/cvacio.png", -8.5, -9, 0.8, 0.8);

	corazon_m1 = new ETSIDI::Sprite("bin/texturas/cmitad.png", -12.5, -9, 0.8, 0.8);
	corazon_m2 = new ETSIDI::Sprite("bin/texturas/cmitad.png", -11.5, -9, 0.8, 0.8);
	corazon_m3 = new ETSIDI::Sprite("bin/texturas/cmitad.png", -10.5, -9, 0.8, 0.8);
	corazon_m4 = new ETSIDI::Sprite("bin/texturas/cmitad.png", -9.5, -9, 0.8, 0.8);
	corazon_m5 = new ETSIDI::Sprite("bin/texturas/cmitad.png", -8.5, -9, 0.8, 0.8);

	tirachinas = new ETSIDI::Sprite("bin/texturas/tirachinas.png", -4, -9, 0.8, 0.8);
	tirachinas_lento = new ETSIDI::Sprite("bin/texturas/tirachinasLento.png", -2, -9, 0.8, 0.8);
	tirachinas_rapido = new ETSIDI::Sprite("bin/texturas/tirachinasRapido.png", 0, -9, 0.8, 0.8);
	espada = new ETSIDI::Sprite("bin/texturas/espada.png", 2, -9, 0.8, 0.8);
	gancho = new ETSIDI::Sprite("bin/texturas/gancho.png", 4, -9, 0.8, 0.8);

	tiempo = new ETSIDI::Sprite("bin/texturas/reloj.png", -12.5, -7.8, 0.8, 0.8);
	bajas = new ETSIDI::Sprite("bin/texturas/skull.png", 9, -8, 0.8, 0.8);
}