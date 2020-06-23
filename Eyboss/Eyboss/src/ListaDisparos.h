#pragma once
#define MAX_DISPAROS 50
#include "Disparo.h"
#include "Caja.h"
#include "Pared.h"
#include "Objeto.h"
#include "Personaje.h"
#include "ListaEnemigos.h"
#include "ListaPlataformas.h"

class ListaDisparos :public Objeto {
private:
	Disparo* lista[MAX_DISPAROS];
	int numero;
public:

	ListaDisparos() :Objeto(TIRACHINAS) {
		numero = 0;
		for (int i = 0; i < MAX_DISPAROS; i++)
			lista[i] = 0;
		index = 1;
	}
	

	//ListaDisparos(){
	//	numero = 0;
	//	for (int i = 0; i < MAX_DISPAROS; i++)
	//		lista[i] = 0;
	//	index = 1;
	//}

	virtual ~ListaDisparos() {}

	bool Agregar(Disparo* d);
	void DestruirContenido();
	void Eliminar(int index);
	void Eliminar(Disparo* d);
	Disparo* operator [] (int i);
	void Inicializa();
	void Mueve(float t);
	void Dibuja();

	Disparo* Colision(Pared p);

	int getNumero() { return numero; }

	void Ataca(Personaje &p);
	void Colision(ListaPlataformas& l);
	void Colision(ListaEnemigos& l);
	void Colision(Caja &c);	
};