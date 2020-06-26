#pragma once
#define MAX_GANCHOS 1
#include "DisparoGancho.h"
#include "Objeto.h"
#include "Protagonista.h"
#include "ListaEnemigos.h"
#include "ListaPlataformas.h"
#include "Interaccion.h"
#include "Global.h"

class O_Gancho :public Objeto {
private:
	DisparoGancho* lista[MAX_GANCHOS];
	int numero;
public:

	O_Gancho() :Objeto(GANCHO) {
		numero = 0;
		for (int i = 0; i < MAX_GANCHOS; i++)
			lista[i] = 0;
		index = 6;
	}
	virtual ~O_Gancho() {}

	bool Agregar(DisparoGancho* d);
	void DestruirContenido();
	void Eliminar(int index);
	void Eliminar(DisparoGancho* d);
	DisparoGancho* operator [] (int i);
	void Inicializa();
	void Mueve(float t);
	void Dibuja();

	DisparoGancho* Colision(Pared p);

	int getNumero() { return numero; }

	void Ataca(Personaje&p);
	void Colision(ListaPlataformas& l);
	void Colision(Caja &c);	
};