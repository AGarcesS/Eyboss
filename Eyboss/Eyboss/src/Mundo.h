#include "Caja.h"
#include "Bonus.h"
#include "Corazon.h"
#include "ListaDisparos.h"
#include "Vector2D.h"
#include "Interfaz.h"
#include "ListaEnemigos.h"
#include "Purk.h"
#include "Protagonista.h"
#include "Personaje.h"
#include "ListaPlataformas.h"
#include "ListaBonus.h"
#include "B_Espada.h"
#include "O_Espada.h"
#include "ListaObjetos.h"
#include "FactoryObjetos.h"
#include "FactoryPlataforma.h"

class Mundo
{
private: 	
	float x_ojo;
	float y_ojo;
	float z_ojo;

	Protagonista protagonista;
	Caja caja;
	Interfaz interfaz;
	ListaEnemigos enemigos;
	ListaPlataformas plataformas;
	ListaBonus bonus;
	ListaObjetos objetos;
	FactoryObjetos factory;	
	FactoryPlataforma factory_p;

	int nivel;
	int o_index[4];

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
