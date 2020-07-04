#include "Protagonista.h"

void Protagonista::Dibuja() {
	if (m_da�o)
		m_parpadeo = !m_parpadeo;

	if (!m_parpadeo)
	{
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y, 0);
		if (velocidad.x > 0)
			animacion->flip(true, false);
		else if (velocidad.x < 0)
			animacion->flip(false, false);
		animacion->draw();
		glPopMatrix();
	}
}

void Protagonista::Reset() {
	vida = 10;
	tiempo0 = 0;
	m_da�o = false;
	m_parpadeo = false;
}