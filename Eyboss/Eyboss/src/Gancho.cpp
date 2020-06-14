#include "ETSIDI.h"
#include "Gancho.h"
#include "glut.h"

Gancho::Gancho() {
	radio = 0.4f;
	altura = 0.0f;
	ancho = 0.2f;
	alturamaxima = 10.0f;
}
void Gancho::SetVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}
void Gancho::SetPos(Vector2D pos) {
	posicion.x = pos.x;
	posicion.y = pos.y;
}
void Gancho::GetO(Vector2D pos) {
	origen.x = pos.x;
	origen.y = pos.y;
}
void Gancho::Dibuja() {
	glPushMatrix();
	glColor3f(0.4f, 0.4f, 0.4f);
	glBegin(GL_LINES);
	glVertex2f(origen.x, origen.y);
	glVertex2f(posicion.x, posicion.y);
	glEnd();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(0.5f, 20, 20);
	glPopMatrix();
}
void Gancho::Mueve(float t) {
	posicion = posicion + velocidad * t;
}