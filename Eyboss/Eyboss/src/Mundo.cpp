#include <math.h>
#include "ETSIDI.h"
#include "Interaccion.h"
#include "Global.h"
#include "Mundo.h"
#include "glut.h"

Mundo::Mundo() {
	for (int i = 0; i < ListaObjetos::n_objetos; i++) {
		o_index[i] = 0;		
	}
	tiempo0 = 0;
}

Mundo::~Mundo() {
	enemigos.DestruirContenido();
	plataformas.DestruirContenido();
	bonus.DestruirContenido();
	objetos.DestruirContenido();
	e_objetos.DestruirContenido();
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
	e_objetos.Dibuja();
	interfaz.ImprimeJuego(protagonista, objetos);
}

void Mundo::Mueve()
{
	protagonista.Mueve(0.025f);	
	enemigos.Mueve(0.025f);
	objetos.Mueve(0.025f);
	e_objetos.Mueve(0.025f);
	objetos.Seguir(protagonista);

	for (int i = 0; i < enemigos.getNumero(); i++) {
		e_objetos.Seguir(*enemigos[i]);
	}

	objetos.Colision(enemigos);
	e_objetos.Colision(protagonista);

	objetos.Colision(plataformas, &protagonista);

	e_objetos.Colision(plataformas);

	for (int i = 0; i < plataformas.getNumero(); i++) {
		if (protagonista.GetMovimiento()) {
			Interaccion::Colision(protagonista, *plataformas[i]);
		}		
		enemigos.Colision(*plataformas[i]);
	}

	for (int i = 0; i < bonus.getNumero(); i++) {
		if (Interaccion::Colision(*bonus[i], protagonista)) {
			bonus[i]->Audio();
			bonus[i]->Accion(protagonista);
			for (int j = 0; j < ListaObjetos::n_objetos; j++) {
				if (o_index[j] == bonus[i]->GetTipo()) { //Si ese índice ya está en el vector se sale
					bonus.Eliminar(bonus[i]);
					return;
				}
				if (o_index[j] == 0) { //Si hay una posición vacía (0), se escribe ahí ese índice
					o_index[j] = bonus[i]->GetTipo();
					factory.Crear(bonus[i]->GetTipo(), objetos);
					bonus.Eliminar(bonus[i]);
					return;
				}
			}
		}
	}		

	for (int i = 0; i < enemigos.getNumero(); i++) {
		if (Interaccion::Cercania(*enemigos[i], protagonista) && enemigos[i]->GetAtaque() != 0) {
			tiempo0++;
			if (tiempo0 == 60) {
				for (int j = 0; j < e_objetos.getNumero(); j++)
				{
					if (enemigos[i]->GetAtaque() == e_objetos[j]->GetTipo()) {
						e_objetos[j]->Ataca(*enemigos[i]);
						break;
					}
				}
				tiempo0 = 0;
			}
		}
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
	protagonista.SetMovimiento(true);
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
		if (protagonista.GetMovimiento()) {
			{
				if (protagonista.GetOn()) {
					protagonista.SetVel(protagonista.GetVel().x, protagonista.GetSalto());
					protagonista.SetAcel(protagonista.GetAcel().x, -9.8f);
					protagonista.SetOn(false);
					ETSIDI::play("bin/sonidos/jump.wav");
				}
				break;
			}
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
		if (protagonista.GetOn() && protagonista.GetVel().y >= 0) {
			for (int i = 0; i < ListaObjetos::n_objetos; i++) {
				if (objetos[i] != NULL)
					if (objetos[i]->GetTipo() == Objeto::GANCHO)
						objetos[i]->Ataca(protagonista);
			}
			break;				
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
	for (int i = 0; i < ListaObjetos::n_objetos; i++) {
		o_index[i] = 0;
	}
	protagonista.SetPos(10, protagonista.GetAltura()/2);
	protagonista.SetVel(0, 0);
	enemigos.DestruirContenido();
	objetos.DestruirContenido();
	e_objetos.DestruirContenido();
	plataformas.DestruirContenido();
	bonus.DestruirContenido();

	if (nivel == 1) {

		factory_e.Crear(Personaje::PURK, enemigos, 0, 27.5, 0, 0, Objeto::TIRACHINAS_LENTO, &e_objetos);
		factory_e.Crear(Personaje::PURK, enemigos, 56, 35.5, 0, 0, Objeto::TIRACHINAS_LENTO, &e_objetos);
		factory_e.Crear(Personaje::PURK, enemigos, 17, 2, 2, 5);
		factory_e.Crear(Personaje::VELOZ, enemigos, 17, 21, 0, 0);
		factory_e.Crear(Personaje::VELOZ, enemigos, 42, 32.5, 0, 0);
		factory_e.Crear(Personaje::TROLL, enemigos, 23, 22, -2, 0);
		factory_e.Crear(Personaje::TROLL, enemigos, 25, 22, 2, 0);
		factory_e.Crear(Personaje::TROLL, enemigos, 27, 22, -2, 0);
		factory_e.Crear(Personaje::TROLL, enemigos, 46, 25.5, 3, 0);
		factory_e.Crear(Personaje::PURK, enemigos, 48, 28.5, 0, 0, Objeto::TIRACHINAS, &e_objetos);

		enemigos.Inicializa(); //Se crea el sprite (solo una vez, válido para cada enemigo)

		//Caja

		
		factory_p.Crear(Pared::NORMAL, plataformas, -4.5f, -2.5f, 22.5f, 0.0f); // primer suelo
		factory_p.Crear(Pared::NORMAL, plataformas, -2.0f, 40.0f, 60.0f, 42.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, -4.5f, 0.0f, -2.0f, 42.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 20.0f, 0.0f, 22.5f, 20.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, 20.0f, 17.5f, 60.0f, 20.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, 60.0f, 17.5f, 62.5f, 42.5f);
		factory_p.Crear(Pared::PUERTA, plataformas, 8, 6, 10.5, 9, 0.45);
		

		//Plataformas
		factory_p.Crear(Pared::NORMAL, plataformas, -2.0f, 2.5f, 1.0f, 3.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, 4.0f, 5.5f, 7.0f, 6.0f);

		factory_p.Crear(Pared::NORMAL, plataformas, 11.0f, 4.0f, 20.0f, 4.5f);

		factory_p.Crear(Pared::NORMAL, plataformas, 13.0f, 7.5f, 16.5f, 8.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, 16.0, 9.75f, 16.5f, 10.1f);//Pared compleja
		factory_p.Crear(Pared::NORMAL, plataformas, 16.0f, 10.0f, 16.5f, 7.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 13.0, 9.75f, 13.5f, 10.1f);//Pared compleja
		factory_p.Crear(Pared::NORMAL, plataformas, 13.0f, 10.0f, 13.5f, 7.5f);

		factory_p.Crear(Pared::NORMAL, plataformas, 4.0f, 13.5f, 8.5f, 14.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, 18.75f, 12.25f, 20.0f, 12.75f);
		factory_p.Crear(Pared::NORMAL, plataformas, -2.0, 16.0f, 0.5f, 16.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 20.0f, 20.0f, 20.5f, 36.0f);//Pared compleja
		factory_p.Crear(Pared::NORMAL, plataformas, 5.25f, 19.0f, 20.0f, 19.5f);

		factory_p.Crear(Pared::SALTO, plataformas, 13.0f, 21.5f, 20.0f, 22.0f);
		factory_p.Crear(Pared::SALTO, plataformas, -2.0f, 7.5f, 2.0f, 8.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, -2.0f, 26.0f, 6.0f, 26.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 18.0f, 24.0f, 20.0f, 24.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 11.0f, 29.0f, 15.0f, 29.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 17.0f, 32.0f, 20.0f, 32.5f);

		factory_p.Crear(Pared::NORMAL, plataformas, 35.0f, 29.0f, 40.5f, 29.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 40.0f, 20.0f, 40.5f, 35.0f);
		factory_p.Crear(Pared::SALTO, plataformas, -2.0f, 28.5f, 1.0f, 29.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, 4.0f, 34.5f, 6.0f, 35.0f);
		factory_p.Crear(Pared::VELOCIDAD, plataformas, 7.0f, 36.0f, 15.0f, 36.5f);
		factory_p.Crear(Pared::SALTO, plataformas, 38.5f, 31.5f, 40.0f, 32.0f);

		factory_p.Crear(Pared::NORMAL, plataformas, 42.0f, 37.0f, 46.0f, 37.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 47.0f, 34.0f, 60.0f, 34.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 40.0f, 31.0f, 56.0f, 31.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 55.0f, 27.0f, 58.0f, 27.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 45.0f, 27.0f, 49.0f, 27.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 44.0f, 24.0f, 60.0f, 24.5f);

		

		//Bonus
		factory_b.Crear(Bonus::ESPADA, bonus, 19, 25.5);
		factory_b.Crear(Bonus::TIRACHINAS, bonus, 19, 33.5);
		factory_b.Crear(Bonus::TIRACHINAS, bonus, 57, 28.5);
		factory_b.Crear(Bonus::TIRACHINAS_LENTO, bonus, -1, 17);
		factory_b.Crear(Bonus::TIRACHINAS_RAPIDO, bonus, 15, 8.5);
		factory_b.Crear(Bonus::GANCHO, bonus, 19.25, 13.25);
		factory_b.Crear(Bonus::CORAZON, bonus, 5, 21);
		factory_b.Crear(Bonus::CORAZON, bonus, 5, 36);
		factory_b.Crear(Bonus::CORAZON, bonus, 37, 30);
		factory_b.Crear(Bonus::CORAZON, bonus, 56, 21);
	}

	if (nivel == 2) {
		factory_p.Crear(Pared::NORMAL, plataformas, -4.5f, -2.5f, 12.5f, 0.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, 10.0f, -2.5f, 12.5f, 3.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, 10.0f, -2.5f, 15.5f, 3.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, 15.5f, -2.5f, 16.5f, 6.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, 16.5f, -2.5f, 23.0f, 4.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 23.0f, -2.5f, 36.0f, 5.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 75.0f, -2.5f, 77.5f, 50.0f);

		factory_p.Crear(Pared::NORMAL, plataformas, -4.5f, 0.0f, -2.0f, 30.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, 20.0f, 9.0f, 32.0f, 30.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, 32.0f, 12.0f, 44.0f, 30.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, 17.0f, 10.5f, 20.0f, 50.0f);

		factory_p.Crear(Pared::NORMAL, plataformas, 36.0f, -2.5f, 49.0f, 8.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 49.0f, -2.5f, 80.0f, 7.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 44.0f, 14.0f, 47.0f, 14.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 48.0f, 11.0f, 52.0f, 11.5f);
		factory_p.Crear(Pared::NORMAL, plataformas, 51.5f, 17.0f, 58.0f, 17.5f);
		factory_p.Crear(Pared::SALTO, plataformas, 59.5f, 19.5f, 62, 20.0f);
		factory_p.Crear(Pared::NORMAL, plataformas, 72.0f, 18.0f, 75.0, 18.5f);
		factory_p.Crear(Pared::SALTO, plataformas, 69.5f, 24.0f, 73.0f, 24.5f);
		factory_p.Crear(Pared::SALTO, plataformas, 64.5f, 30.0f, 67.0f, 30.5f);
		factory_p.Crear(Pared::VELOCIDAD, plataformas, 57.0f, 36.0f, 61.0f, 36.5f);



		factory_e.Crear(Personaje::TROLL, enemigos, 52, 8.5, -2, 0);
		factory_e.Crear(Personaje::TROLL, enemigos, 59, 8.5, -2, 0);
		factory_e.Crear(Personaje::VELOZ, enemigos, 18, 6, 3, 0);


		factory_b.Crear(Bonus::ESPADA, bonus, 12, 4);
	}

	if (nivel == 3) {
	
	}

	if (nivel <= 3)
		return true;
	else
		return false;
}