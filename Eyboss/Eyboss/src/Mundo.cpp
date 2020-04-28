#include"Interaccion.h"
#include <math.h>

#include "glut.h"
#include "Mundo.h"

Mundo::~Mundo() {
	disparos.DestruirContenido();
}

void Mundo::Dibuja()
{
	gluLookAt(protagonista.GetPos().x, protagonista.GetPos().y, 30,  // posicion del ojo
			protagonista.GetPos().x, protagonista.GetPos().y, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, protagonista.GetPos().y, 0.0);     // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo

	caja.Dibuja();
	protagonista.Dibuja();
	disparos.Dibuja();
	plataforma.Dibuja();
	bonus.Dibuja();	
}

void Mundo::Mueve()
{
	protagonista.Mueve(0.025f);	
	bonus.Mueve(0.025f);
	disparos.Mueve(0.025f);
	disparos.Colision(caja);
	disparos.Colision(plataforma);

	Interaccion::Colision(protagonista, caja);
	Interaccion::Colision(protagonista, plataforma);


	Disparo* aux1 = disparos.Colision(caja);
	if (aux1 != 0)
		disparos.Eliminar(aux1);

	Disparo* aux2 = disparos.Colision(plataforma);
	if (aux2 != 0)
		disparos.Eliminar(aux2);
}

void Mundo::Inicializa()
{
	bonus.SetPos(5.0f, 5.0f);

	plataforma.SetPos(-5.0f, 2.0f, 5.0f, 2.5f);	
}

void Mundo::Tecla(unsigned char key)
{
	switch (key) {
	
	case ' ': //Salto
		if (protagonista.GetOn()) {
			protagonista.SetVel(protagonista.GetVel().x, protagonista.GetSalto());
			protagonista.SetAcel(protagonista.GetAcel().x, -9.8f);
			protagonista.SetOn(false);
		}
		break;		
	case 'q': //Cierra la pantalla
		exit(0);
		break;
	}
}

void Mundo::TeclaEspecial(unsigned char key) {
	switch (key) {
	case GLUT_KEY_LEFT:	
		protagonista.SetVel(-5.0f, protagonista.GetVel().y);
		break;
	case GLUT_KEY_RIGHT:		
		protagonista.SetVel(5.0f,protagonista.GetVel().y);		
		break;
	case GLUT_KEY_UP:
		Disparo* d = new Disparo();
		Vector2D pos = protagonista.GetPos();
		Vector2D vel = protagonista.GetVel();
		d->SetPos(pos.x, pos.y);
		if (vel.x > 0)
			d->SetVel(7.0f, 0.0f);
		else if (vel.x < 0)
			d->SetVel(-7.0f, 0.0f);		
		disparos.Agregar(d);
		break;
	}
}

void Mundo::TeclaMantenida(unsigned char key) { //Si se deja de pulsar la tecla
	switch (key) {
	case GLUT_KEY_RIGHT:
		protagonista.SetVel(0.0f, 0.0f);
		break;
	case GLUT_KEY_LEFT:
		protagonista.SetVel(0.0f, 0.0f);
		break;
	}
}
