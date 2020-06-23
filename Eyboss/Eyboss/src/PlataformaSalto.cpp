#include <math.h>
#include "ETSIDI.h"
#include "Pared.h"
#include "PlataformaSalto.h"
#include "glut.h"

void PlataformaSalto::Dibuja(float k) {                                                       //Implementar texturas
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(textura).id);
	glDisable(GL_LIGHTING);

	glTranslatef(0, 0, z); //Se dibuja en un plano un poco por atrás del resto de objetos

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(k * limite1.x, k * limite2.y); glVertex2f(limite1.x, limite2.y);
	glTexCoord2d(k * limite2.x, k * limite2.y); glVertex2f(limite2.x, limite2.y);
	glTexCoord2d(k * limite2.x, k * limite1.y); glVertex2f(limite2.x, limite1.y);
	glTexCoord2d(k * limite1.x, k * limite1.y); glVertex2f(limite1.x, limite1.y);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}