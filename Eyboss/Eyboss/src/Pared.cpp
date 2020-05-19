#include <math.h>
#include "ETSIDI.h"
#include "Pared.h"
#include "glut.h"


Pared::Pared() {
	rojo = verde = azul = 255;
	textura = "bin/texturas/floor.png";	
}	

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


void Pared::SetTextura(const char* text) {
	textura = text;
}

void Pared::Dibuja() {                                                       //Implementar texturas
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(textura).id);
	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0.5*limite1.x, 0.5 * limite2.y); glVertex2f(limite1.x, limite2.y);
	glTexCoord2d(0.5 * limite2.x, 0.5 * limite2.y); glVertex2f(limite2.x, limite2.y);
	glTexCoord2d(0.5 * limite2.x, 0.5 * limite1.y); glVertex2f(limite2.x, limite1.y);
	glTexCoord2d(0.5 * limite1.x, 0.5 * limite1.y); glVertex2f(limite1.x, limite1.y);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

//void Pared::Dibuja() {
//	glDisable(GL_LIGHTING);
//	glColor3ub(rojo, verde, azul);
//	glRectd(limite1.x, limite1.y, limite2.x, limite2.y);	
//	glEnable(GL_LIGHTING);
//}

float Pared::distanciap_r(Vector2D punto1, Vector2D punto2, Vector2D punto3, Vector2D* dir) {
	Vector2D u = punto3 - punto1;
	Vector2D v = (punto2 - punto1).Unitario();
	float longitud = (punto1 - punto2).modulo();
	float valor = u * v;
	float distancia = 0;
	if (valor < 0)
		*dir = u;
	else if (valor > longitud)
		*dir = (punto3 - punto2);
	else
		*dir = u - v * valor;
	return distancia = dir->modulo();
}
