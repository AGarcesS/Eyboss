#pragma once
#include "Vector2D.h"
#include "Pared.h"

class ParedPuerta : public Pared {
public:
	ParedPuerta() :Pared(PUERTA) {
		rojo = verde = azul = 255;
		textura = "bin/texturas/puerta.png";
		z = 0;
	}
	virtual ~ParedPuerta() {}

	void Dibuja() {                                                       //Implementar texturas
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(textura).id);
		glDisable(GL_LIGHTING);

		glTranslatef(0, 0, z); //Se dibuja en un plano un poco por atrás del resto de objetos

		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 0); glVertex2f(limite1.x, limite2.y);
		glTexCoord2d(1, 0); glVertex2f(limite2.x, limite2.y);
		glTexCoord2d(1, 1); glVertex2f(limite2.x, limite1.y);
		glTexCoord2d(0, 1); glVertex2f(limite1.x, limite1.y);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	friend class Interaccion;
};