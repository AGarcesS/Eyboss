#include "Caja.h"
#include "Bonus.h"
#include "Disparo.h"
#include "ListaDisparos.h"
#include "Vector2D.h"
#include "Tiempo.h"
#include "Interfaz.h"
#include "ListaEnemigos.h"
#include "Purk.h"
#include "Protagonista.h"
#include "Personaje.h"
#include "ListaPlataformas.h"
#include "ListaBonus.h"
#include "Corazon.h"

class Mundo
{
private: 	
	float x_ojo;
	float y_ojo;
	float z_ojo;

	float t;

	Protagonista protagonista;
	Purk purk;
	Caja caja;
	Pared plataforma;		
	ListaDisparos disparos;
	Interfaz interfaz;
	Tiempo tiempo;
	ListaEnemigos enemigos;
	ListaPlataformas plataformas;
	ListaBonus bonus;

	int nivel;

public:
	Mundo();
	virtual ~Mundo();

	Vector2D GetOjo();

	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);
	void TeclaMantenida(unsigned char key);
	void Inicializa();
	void Mueve();
	void Dibuja();		

	bool CargarNivel();
};
