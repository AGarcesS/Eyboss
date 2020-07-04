#include <math.h>
#include "ETSIDI.h"
#include "Pared.h"
#include "glut.h"


void Pared::SetColor(unsigned char r, unsigned char v, unsigned char a){
	rojo = r;
	verde = v;
	azul = a;
}

void Pared::SetPos(float x1, float y1, float x2, float y2) {
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}

void Pared::Dibuja() {                                                       
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(textura).id);
	glDisable(GL_LIGHTING);

	float k = 0.1; //zoom de la textura para las plataformas
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

float Pared::distanciap_r(Vector2D recta1, Vector2D recta2, Vector2D punto, Vector2D* dir) {
	Vector2D u = punto - recta1;
	Vector2D v = (recta2 - recta1).Unitario();
	float longitud = (recta1 - recta2).modulo();
	Vector2D direccion;
	float valor = u * v;
	float distancia = 0;

	if (valor < 0)
		direccion = u;
	else if (valor > longitud)
		direccion = (punto - recta2);
	else
		direccion = u - v * valor;
	distancia = direccion.modulo();
	if (dir != 0)
		*dir = direccion.Unitario();
	return distancia;
}
