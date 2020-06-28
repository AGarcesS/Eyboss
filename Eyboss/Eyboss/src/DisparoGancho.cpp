#include "DisparoGancho.h"
#include "glut.h"


void DisparoGancho::Dibuja() {
    GLfloat thickness = 5.0;
    glLineWidth(thickness);
    glColor3f(0.2f, 0.2f, 0.2f);
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
    glVertex2f(posorigen.x, posorigen.y);
    glVertex2f(posicion.x, posicion.y);
    glEnd();
    glEnable(GL_LIGHTING);
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    if (orientacion)
        sprite->flip(false, false);
    else
        sprite->flip(true, false);;
    sprite->draw();
    glPopMatrix();
}


void DisparoGancho::SetPosOr(float ix, float iy) {
    posorigen.x = ix;
    posorigen.y = iy;
}

void DisparoGancho::Mueve(float t) {
    posicion = posicion + velocidad * t + aceleracion * (0.5 * t * t);
    velocidad = velocidad + aceleracion * t;
}

bool DisparoGancho::Limite() {
    Vector2D pos = posicion - posorigen;
    if (longitud <= pos.modulo())
        return true;
    else
        return false;
}

void DisparoGancho::SetF(bool f) {
    feuer = f;
}
bool DisparoGancho::GetF() {
    return feuer;
}
Vector2D DisparoGancho::GetOr() {
    return posorigen;
}