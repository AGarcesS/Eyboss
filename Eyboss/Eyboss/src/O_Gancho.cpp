#include "O_Gancho.h"
#include "glut.h"
#include "Interaccion.h"


void O_Gancho::Inicializa() {
    sprite = new ETSIDI::Sprite(textura, 0.0f, 0.0f, ancho, altura);
}



void O_Gancho::Dibuja() {
    glColor3f(0.0f, 1.0f, 1.0f);
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
    glVertex2f(posorigen.x, posorigen.y);
    glVertex2f(posicion.x, posicion.y);
    glEnd();
    glEnable(GL_LIGHTING);
 /*   glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    glutSolidSphere(altura, 20, 20);
    glPopMatrix();
*/
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    if (orientacion)
        sprite->flip(false, false);
    else
        sprite->flip(true, false);;
    sprite->draw();
    //glTranslatef(-posicion.x, -posicion.y, 0);
    glPopMatrix();
}



void O_Gancho::SetPosOr(float ix, float iy) {
    posorigen.x = ix;
    posorigen.y = iy;
}



void O_Gancho::Mueve(float t) {
    posicion = posicion + velocidad * t + aceleracion * (0.5 * t * t);
    velocidad = velocidad + aceleracion * t;
}



bool O_Gancho::Limite() {
    Vector2D pos = posicion - posorigen;
    if (longitud <= pos.modulo())
        return true;
    else
        return false;
}



void O_Gancho::SetF(bool f) {
    feuer = f;
}
bool O_Gancho::GetF() {
    return feuer;
}



Vector2D O_Gancho::GetOr() {
    return posorigen;
}

void O_Gancho::Ataca(Personaje& p) {
    orientacion = p.GetOrientacion();

    if (orientacion)
        velocidad.x = 7;
    else
        velocidad.x = -7;

    velocidad.y = 7;

    posorigen.x = posicion.x = p.GetPos().x;
    posorigen.y = posicion.y = p.GetPos().y;

    
    /*
    orientacion = p.GetOrientacion();
    float dist;
    if (orientacion)
        dist = p.GetPos().x + p.GetAncho() / 2 + ancho / 2;
    else
        dist = p.GetPos().x - (p.GetAncho() / 2 + ancho / 2);

    SetPos(dist, p.GetPos().y);
    ETSIDI::play("bin/sonidos/Espada1.wav");
    */
}