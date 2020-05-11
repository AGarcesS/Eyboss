#include <string>
#include "glut.h"
#include "Texto.h"

Texto::Texto() {
	text = "Vida";
	posicion.x = 10;
	posicion.y = 580;
	rojo = 255;
	verde = 0;
	azul = 0;
}

Texto::Texto(const char* text, Vector2D pos, float r, float v, float a) {

}

void Texto::Imprimir() {
	int len = strlen(text);
	glColor3f(rojo, verde, azul);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(posicion.x, posicion.y);

	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
	}

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}