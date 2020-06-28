#pragma once
#include "Objeto.h"
#include "ListaPlataformas.h"
#include "ListaEnemigos.h"
#include "Personajes.h"

class ListaObjetos {
public:
	static const int n_objetos = 20;
private:
	Objeto* lista[n_objetos];
	int numero;
public:
	ListaObjetos();
	virtual ~ListaObjetos() {}

	bool Agregar(Objeto* o);
	void DestruirContenido();
	void Eliminar(int index);
	void Eliminar(Objeto* o);
	void Dibuja();
	void Ataca(Personaje& p);
	void Colision(ListaPlataformas& p, Personaje* pe=NULL);
	void Colision(Personaje& p);
	void Colision(ListaEnemigos& p);
	void Mueve(float t);
	void Seguir(Personaje& p);

	Objeto* operator[] (int i);

	int getNumero() { return numero; }
	int getIndex(Objeto* o) { return o->index; }
};