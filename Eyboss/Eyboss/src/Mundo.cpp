#include"Interaccion.h"
#include <math.h>
#include "ETSIDI.h"
#include "glut.h"
#include "Mundo.h"

Mundo::Mundo() {
	t = 0;
}

Mundo::~Mundo() {
	disparos.DestruirContenido();
	protagonista.DestruirContenido();
}

Vector2D Mundo::GetOjo() {
	Vector2D ojo;
	ojo.x = x_ojo;
	ojo.y = y_ojo;
	return ojo;
}

void Mundo::Dibuja()
{
	gluLookAt(protagonista.GetPos().x, protagonista.GetPos().y, 30,	// posicion del ojo
			protagonista.GetPos().x, protagonista.GetPos().y, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, protagonista.GetPos().y, 0.0);     // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo

	caja.Dibuja();
	protagonista.Dibuja();
	disparos.Dibuja();
	plataforma.Dibuja();
	bonus.Dibuja();	
	interfaz.ImprimeJuego(protagonista, tiempo);
}

void Mundo::Mueve()
{
	protagonista.Mueve(0.025f);	
	bonus.Mueve(0.025f);
	disparos.Mueve(0.025f);

	Interaccion::Colision(protagonista, caja);
	Interaccion::Colision(protagonista, plataforma);

	Disparo* aux = disparos.Colision(caja);
	if (aux != 0)
		disparos.Eliminar(aux);

	Disparo* aux1 = disparos.Colision(plataforma);
	if (aux1 != 0)
		disparos.Eliminar(aux1);

	t++;
	tiempo.SetTiempo(t);
	if (tiempo.GetReset())
		t = 0.0f;
}

void Mundo::Inicializa()
{
	bonus.SetPos(5.0f, 5.0f);
	protagonista.Inicializa();

	x_ojo = protagonista.GetPos().x;
	y_ojo = protagonista.GetPos().y;
	z_ojo = 30;

	nivel = 0;
	CargarNivel();	
}

void Mundo::Tecla(unsigned char key)
{
	switch (key) {
	
	case ' ': //Salto
		if (protagonista.GetOn()) {
			protagonista.SetVel(protagonista.GetVel().x, protagonista.GetSalto());
			protagonista.SetAcel(protagonista.GetAcel().x, -9.8f);
			protagonista.SetOn(false);
			ETSIDI::play("bin/sonidos/jump.wav");
		}
		break;			
	}
}

void Mundo::TeclaEspecial(unsigned char key) {
	switch (key) {
	case GLUT_KEY_LEFT:	
		protagonista.SetVel(-5.0f, protagonista.GetVel().y);
		protagonista.SetOrientacion(false);
		break;
	case GLUT_KEY_RIGHT:		
		protagonista.SetVel(5.0f,protagonista.GetVel().y);		
		protagonista.SetOrientacion(true);
		break;
	case GLUT_KEY_UP:
		Disparo* d = new Disparo();
		Vector2D pos = protagonista.GetPos();
		Vector2D vel = protagonista.GetVel();
		d->SetPos(pos.x, pos.y);
		if (protagonista.GetOrientacion())
			d->SetVel(7.0f, 0.0f);
		else
			d->SetVel(-7.0f, 0.0f);		
		disparos.Agregar(d);
		ETSIDI::play("bin/sonidos/shoot.wav");
		break;
	}
}

void Mundo::TeclaMantenida(unsigned char key) { //Si se deja de pulsar la tecla
	switch (key) {
	case GLUT_KEY_RIGHT:
		protagonista.SetVel(0.0f, protagonista.GetVel().y);
		break;
	case GLUT_KEY_LEFT:
		protagonista.SetVel(0.0f, protagonista.GetVel().y);
		break;
	}
}

bool Mundo::CargarNivel() {
	nivel++;
	protagonista.SetPos(0, 0);
	disparos.DestruirContenido();

	if (nivel == 1) {
		plataforma.SetPos(-5.0f, 2.0f, 5.0f, 2.5f);
		plataforma.SetTextura("bin/texturas/wall.png");
	}

	if (nivel == 2) {
		plataforma.SetPos(-3.0f, 6.0f, 3.0f, 6.0f);
		plataforma.SetColor(255, 0, 0);
	}

	if (nivel == 3) {
		plataforma.SetPos(-10.0f, 12.0f, 4.0f, 10.0f);
		plataforma.SetColor(255, 0, 255);
	}

	if (nivel <= 3)
		return true;
	else
		return false;
}