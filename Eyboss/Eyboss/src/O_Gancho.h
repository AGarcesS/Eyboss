#pragma once
#define MAX_GANCHOS 1
#include "DisparoGancho.h"
#include "Objeto.h"
#include "Personaje.h"
#include "ListaEnemigos.h"
#include "ListaPlataformas.h"
#include "Interaccion.h"
#include "Global.h"

class O_Gancho :public Objeto {
private:
	Disparo* lista[MAX_GANCHOS];
	int numero;
public:

	O_Gancho() :Objeto(GANCHO) {
		numero = 0;
		for (int i = 0; i < MAX_GANCHOS; i++)
			lista[i] = 0;
		index = 6;
	}
	virtual ~O_Gancho() {}

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
	void Colision(Caja &c);	
};