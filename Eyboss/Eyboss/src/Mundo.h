#include "Caja.h"
#include "Protagonista.h"
#include "Bonus.h"
#include "Disparo.h"
#include "ListaDisparos.h"

class Mundo
{
private: 	
	Disparo disparo;
	Protagonista protagonista;
	Caja caja;
	Bonus bonus;
	Pared plataforma;	
	ListaDisparos disparos;
public:
	Mundo() {};
	virtual ~Mundo();

	void Tecla(unsigned char key);
	void TeclaEspecial(unsigned char key);
	void TeclaMantenida(unsigned char key);
	void Inicializa();
	void Mueve();
	void Dibuja();		
};
