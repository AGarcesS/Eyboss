#include <math.h>
#include "ETSIDI.h"
#include "Interaccion.h"
#include "Global.h"
#include "Mundo.h"
#include "glut.h"

Mundo::Mundo() {
	for (int i = 0; i < 4; i++) {
		o_index[i] = 0;
	}
}

Mundo::~Mundo() {
	enemigos.DestruirContenido();
	plataformas.DestruirContenido();
	bonus.DestruirContenido();
	objetos.DestruirContenido();
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

	protagonista.Dibuja();	
	enemigos.Dibuja();	
	caja.Dibuja();	
	plataformas.Dibuja();
	bonus.Dibuja();	
	objetos.Dibuja();
	interfaz.ImprimeJuego(protagonista);
}

void Mundo::Mueve()
{
	protagonista.Mueve(0.025f);	
	enemigos.Mueve(0.025f);
	objetos.Mueve(0.025f);

	objetos.Colision(enemigos);
	objetos.Colision(plataformas);
	objetos.Colision(caja);
	
	Interaccion::Colision(protagonista, caja);

	for (int i = 0; i < enemigos.getNumero(); i++) {
		Interaccion::Cercania(protagonista, *enemigos[i]);
	}

	for (int i = 0; i < plataformas.getNumero(); i++) {
		Interaccion::Colision(protagonista, *plataformas[i]);
		enemigos.Colision(*plataformas[i]);
	}

	for (int i = 0; i < bonus.getNumero(); i++) {
		if (Interaccion::Colision(*bonus[i], protagonista)) {
			bonus[i]->Audio();
			for (int j = 0; j < 4; j++) {
				if (o_index[j] == bonus[i]->GetIndex()) { //Si ese �ndice ya est� en el vector se sale
					bonus.Eliminar(bonus[i]);
					return;
				}
				if (o_index[j] == 0) { //Si hay una posici�n vac�a (0), se escribe ah� ese �ndice
					o_index[j] = bonus[i]->GetIndex();
					factory.Crear(bonus[i]->GetIndex(), objetos);
					bonus.Eliminar(bonus[i]);
					return;
				}
			}
		}
	}		

	for (int i = 0; i < enemigos.getNumero(); i++) {
		if (Interaccion::Colision(*enemigos[i], protagonista)) {
			enemigos.Eliminar(enemigos[i]);
		}
	}

	enemigos.Colision(caja);

	Global::tiempo++;
	if (Global::reset)
		Global::tiempo = 0;	
}

void Mundo::Inicializa()
{
	protagonista.Inicializa();
	interfaz.Inicializa();
	Global::tiempo = 0;
	Global::bajas = 0;		

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
	{
		if (protagonista.GetOn()) {
			protagonista.SetVel(protagonista.GetVel().x, protagonista.GetSalto());
			protagonista.SetAcel(protagonista.GetAcel().x, -9.8f);
			protagonista.SetOn(false);
			ETSIDI::play("bin/sonidos/jump.wav");
		}
		break;
	}
	case 'q': //Tirachinas
	{
		for (int i = 0; i < ListaObjetos::n_objetos; i++) {
			if (objetos[i] != NULL)
				if (objetos[i]->GetTipo() == Objeto::TIRACHINAS)
					objetos[i]->Ataca(protagonista);
		}
		break;
	}				
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
	enemigos.DestruirContenido();
	objetos.DestruirContenido();
	plataformas.DestruirContenido();	

	if (nivel == 1) {

		Purk* a = new Purk();
		Purk* b = new Purk();
		Purk* c = new Purk();
		a->SetVel(0, 3);
		b->SetPos(5, 3);
		b->SetVel(3, 5);
		c->SetPos(-5, 3);
		c->SetVel(-1, 0);
		enemigos.Agregar(a);
		enemigos.Agregar(b);
		enemigos.Agregar(c);
		enemigos.Inicializa(); //Se crea el sprite (solo una vez, v�lido para cada purk)

		Pared* d = new Pared();
		Pared* h = new Pared();
		d->SetPos(7.0f, 2.0f, 17.0f, 2.5f);
		h->SetPos(-5.0f, 2.0f, 5.0f, 2.5f);
		plataformas.Agregar(d);
		plataformas.Agregar(h);

		Corazon* e = new Corazon();
		Corazon* f = new Corazon();
		Corazon* g = new Corazon();
		e->SetPos(12, 3);
		f->SetPos(0, 3);
		g->SetPos(15, 1);
		bonus.Agregar(e);
		bonus.Agregar(f);
		bonus.Agregar(g);
		bonus.Inicializa();
	}

	if (nivel == 2) {
	
	}

	if (nivel == 3) {
	
	}

	if (nivel <= 3)
		return true;
	else
		return false;
}