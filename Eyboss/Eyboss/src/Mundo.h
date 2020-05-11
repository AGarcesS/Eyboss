#include "Caja.h"
#include "Protagonista.h"
#include "Bonus.h"
#include "Disparo.h"
#include "ListaDisparos.h"
#include "Vector2D.h"
#include "Tiempo.h"
#include "Interfaz.h"

class Mundo
{
private: 	
	float x_ojo;
	float y_ojo;
	float z_ojo;

	float t;

	Disparo disparo;
	Protagonista protagonista;
	Caja caja;
	Bonus bonus;
	Pared plataforma;	
	ListaDisparos disparos;
	Interfaz interfaz;
	Tiempo tiempo;

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
