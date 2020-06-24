#include "O_Espada.h"
#include "Interaccion.h"

void O_Espada::Inicializa() {
	sprite = new ETSIDI::Sprite(textura, 0.0f, 0.0f, ancho, altura);
}

void O_Espada::Dibuja() {
	glColor3f(0.0f, 1.0f, 1.0f);
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

void O_Espada::SetPos(float ex, float ey) {
	posicion.x = ex;
	posicion.y = ey;
}

Vector2D O_Espada::GetPos() {
	return posicion;
}

void O_Espada::Ataca(Personaje& p) {
	orientacion = p.GetOrientacion();
	float dist;
	if (orientacion)
		dist = p.GetPos().x + p.GetAncho() / 2 + ancho / 2;
	else
		dist = p.GetPos().x - (p.GetAncho() / 2 + ancho / 2);

	SetPos(dist, p.GetPos().y);
	ETSIDI::play("bin/sonidos/Espada1.wav");
}

void O_Espada::Colision(ListaEnemigos& l) {
	for (int i = 0; i < l.getNumero(); i++) {
		if (Interaccion::Colision(*this, *l[i])) {
			if (l[i]->GetVida() > 0) {
				l[i]->SetVida(-3);
			}
			else {
				l.Eliminar(l[i]);
			}
			break;
		}
	}
}