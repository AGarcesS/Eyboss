#include <math.h>
#include "ETSIDI.h"
#include "Interaccion.h"
#include "Global.h"
#include "Mundo.h"
#include "glut.h"

Mundo::Mundo() {
	for (int i = 0; i < 6; i++) {
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

	plataformas.Dibuja();
	protagonista.Dibuja();	
	enemigos.Dibuja();
	bonus.Dibuja();	
	objetos.Dibuja();
	interfaz.ImprimeJuego(protagonista);
}

void Mundo::Mueve()
{
	protagonista.Mueve(0.025f);	
	enemigos.Mueve(0.025f);
	objetos.Mueve(0.025f);
	objetos.Seguir(protagonista);

	objetos.Colision(enemigos);
	objetos.Colision(plataformas);

	for (int i = 0; i < plataformas.getNumero(); i++) {
		Interaccion::Colision(protagonista, *plataformas[i]);
		enemigos.Colision(*plataformas[i]);
	}

	for (int i = 0; i < bonus.getNumero(); i++) {
		if (Interaccion::Colision(*bonus[i], protagonista)) {
			bonus[i]->Audio();
			bonus[i]->Accion(protagonista);
			for (int j = 0; j < 6; j++) {
				if (o_index[j] == bonus[i]->GetIndex()) { //Si ese índice ya está en el vector se sale
					bonus.Eliminar(bonus[i]);
					return;
				}
				if (o_index[j] == 0) { //Si hay una posición vacía (0), se escribe ahí ese índice
					o_index[j] = bonus[i]->GetIndex();
					factory.Crear(bonus[i]->GetIndex(), objetos);
					bonus.Eliminar(bonus[i]);
					return;
				}
			}
		}
	}		

	for (int i = 0; i < enemigos.getNumero(); i++) {
		Interaccion::Cercania(*enemigos[i], protagonista);
	}

	for (int i = 0; i < enemigos.getNumero(); i++) {
		if (Interaccion::Colision(*enemigos[i], protagonista)) {
			switch (enemigos[i]->GetTipo()) {
			case Personaje::PURK:
			{
				protagonista.SetVida(-enemigos[i]->GetDaño());
				break;
			}
			case Personaje::TROLL:
			{
				protagonista.SetVida(-enemigos[i]->GetDaño());
				break;
			}
			case Personaje::VELOZ:
			{
				protagonista.SetVida(-enemigos[i]->GetDaño());
				break;
			}
			}
		}
	}

	Global::tiempo++;
	if (Global::reset)
		Global::tiempo = 0;	

	Global::vida = protagonista.GetVida();
}

void Mundo::Inicializa()
{
	protagonista.Reset();
	protagonista.Inicializa();
	interfaz.Inicializa();
	Global::tiempo = 0;
	Global::bajas = 0;	
	Global::municion = Global::municionlenta = Global::municionrapida = 0;

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
				if (objetos[i]->GetTipo() == Objeto::TIRACHINAS) {
					objetos[i]->Ataca(protagonista);
					break;
				}				
		}
		break;
	}
	case 'w': //Tirachinas lento
	{
		for (int i = 0; i < ListaObjetos::n_objetos; i++) {
			if (objetos[i] != NULL)
				if (objetos[i]->GetTipo() == Objeto::TIRACHINAS_LENTO) {
					objetos[i]->Ataca(protagonista);
					break;
				}					
		}
		break;
	}
	case 'e': //Tirachinas rápido
	{
		for (int i = 0; i < ListaObjetos::n_objetos; i++) {
			if (objetos[i] != NULL)
				if (objetos[i]->GetTipo() == Objeto::TIRACHINAS_RAPIDO) {
					objetos[i]->Ataca(protagonista);
					break;
				}					
		}
		break;
	}
	case 'r': //Espada
	{
		for (int i = 0; i < ListaObjetos::n_objetos; i++) {
			if (objetos[i] != NULL)
				if (objetos[i]->GetTipo() == Objeto::ESPADA) {
					objetos[i]->Ataca(protagonista);
					break;
				}					
		}
		break;
	}
	case 't': //Gancho
		for (int i = 0; i < ListaObjetos::n_objetos; i++) {
			if (objetos[i] != NULL)
				if (objetos[i]->GetTipo() == Objeto::GANCHO) {
					objetos[i]->Ataca(protagonista);
					break;
				}					
		}
		break;
	}
}

void Mundo::TeclaEspecial(unsigned char key) {
	if (protagonista.GetMovimiento()) {
	switch (key) {
	case GLUT_KEY_LEFT:
		protagonista.SetVel(-5.0f, protagonista.GetVel().y);
		protagonista.SetOrientacion(false);
		break;
	case GLUT_KEY_RIGHT:
		protagonista.SetVel(5.0f, protagonista.GetVel().y);
		protagonista.SetOrientacion(true);
		break;
		}
	}
}

void Mundo::TeclaMantenida(unsigned char key) { //Si se deja de pulsar la tecla
	if (protagonista.GetMovimiento()) {
		switch (key) {
		case GLUT_KEY_RIGHT:
			protagonista.SetVel(0.0f, protagonista.GetVel().y);
			break;
		case GLUT_KEY_LEFT:
			protagonista.SetVel(0.0f, protagonista.GetVel().y);
			break;
		}
	}
}

bool Mundo::CargarNivel() {
	nivel++;
	for (int i = 0; i < 6; i++) {
		o_index[i] = 0;
	}
	protagonista.SetPos(10, protagonista.GetAltura()/2);
	protagonista.SetVel(0, 0);
	enemigos.DestruirContenido();
	objetos.DestruirContenido();
	plataformas.DestruirContenido();
	bonus.DestruirContenido();

	if (nivel == 1) {

		// Enemigos
		factory_e.Crear(Personaje::PURK, enemigos, 0, 8, 2, 3);
		factory_e.Crear(Personaje::PURK, enemigos, 5, 3, 2, 5);
		factory_e.Crear(Personaje::VELOZ, enemigos, 30, 2, -4, 0);
		factory_e.Crear(Personaje::TROLL, enemigos, 40, 4, -2, 3);

		enemigos.Inicializa(); //Se crea el sprite (solo una vez, válido para cada enemigo)

		//Caja
		factory_p.Crear(Pared::NORMAL, plataformas, -10.0f, -0.5f, 80.0f, 0.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, -10.0f, 15.0f, 80.0f, 15.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, -10.5f, 0.0f, -10.0f, 15.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, 80.0f, 0.0f, 80.5f, 15.0f);

		//Plataformas
		factory_p.Crear(Pared::VELOCIDAD, plataformas, 7.0f, 2.0f, 17.0f, 2.5f);
		factory_p.Crear(Pared::SALTO, plataformas, -5.0f, 2.0f, 5.0f, 2.5f);
		factory_p.Crear(Pared::SALTO, plataformas, 20.0f, 6.5f, 30.0f, 6.0f);

		Corazon* e = new Corazon();
		B_Espada* f = new B_Espada();
		B_Tirachinas* g = new B_Tirachinas();
		B_Tirachinas* h = new B_Tirachinas();
		B_TirachinasLento* i = new B_TirachinasLento();
		B_TirachinasRapido* j = new B_TirachinasRapido();
		B_Gancho* k = new B_Gancho();
		e->SetPos(12, 3);
		f->SetPos(0, 3);
		g->SetPos(15, 1);
		h->SetPos(18, 1);
		i->SetPos(5, 3);
		j->SetPos(-4, 1);
		k->SetPos(3, 1);
		bonus.Agregar(e);
		bonus.Agregar(f);
		bonus.Agregar(g);
		bonus.Agregar(h);
		bonus.Agregar(i);
		bonus.Agregar(j);
		bonus.Agregar(k);
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