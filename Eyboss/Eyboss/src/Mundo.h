#include "Bonus.h"
#include "Corazon.h"
#include "ListaDisparos.h"
#include "Vector2D.h"
#include "Interfaz.h"
#include "ListaEnemigos.h"
#include "Protagonista.h"
#include "Personaje.h"
#include "ListaPlataformas.h"
#include "ListaBonus.h"
#include "B_Espada.h"
#include "B_Gancho.h"
#include "B_Tirachinas.h"
#include "B_TirachinasLento.h"
#include "B_TirachinasRapido.h"
#include "O_Espada.h"
#include "O_Gancho.h"
#include "ListaObjetos.h"
#include "FactoryObjetos.h"
#include "FactoryPlataforma.h"
#include "FactoryEnemigos.h"
#include "FactoryBonus.h"

class Mundo
{
private: 	
	float x_ojo;
	float y_ojo;
	float z_ojo;

	Protagonista protagonista;
	Interfaz interfaz;
	ListaEnemigos enemigos;
	ListaPlataformas plataformas;
	ListaBonus bonus;
	ListaObjetos objetos; //lista de objetos del protagonista
	ListaObjetos e_objetos; //lista de objetos de los enemigos
	FactoryObjetos factory;	
	FactoryPlataforma factory_p;
	FactoryEnemigos factory_e;
	FactoryBonus factory_b;
	float tiempo0; //tiempo inicial para gestionar el uso de objetos de los enemigos

	int o_index[ListaObjetos::n_objetos]; //vector auxiliar para gestionar los objetos del protagonista

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

	void CargarNivel();
};
