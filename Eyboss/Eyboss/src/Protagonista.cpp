#include "Protagonista.h"

void Protagonista::Dibuja() {

	/*glEnable(GL_TEXTURE_2D);                                                    //Texturas
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("pers.png").id);
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1, 1, 1);
	glRectd(-ancho / 2, -altura / 2, ancho / 2, altura / 2);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();*/

	/*glPushMatrix();                                                            //Rectangulo
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectd(-ancho/2, -altura/2, ancho/2, altura/2);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();*/

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	if (velocidad.x > 0)
		animacion->flip(true, false);
	else if (velocidad.x < 0)
		animacion->flip(false, false);
	animacion->draw();
	glPopMatrix();
}

void Protagonista::ResetVida() {
	vida = 10;
}