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
	void Ataca(Personaje& p); //ataque de cada objeto
	void Colision(ListaPlataformas& p, Personaje* pe = NULL); //información de personaje solo necesaria para gancho
	void Colision(Personaje& p);
	void Colision(ListaEnemigos& p);
	void Mueve(float t);
	void Seguir(Personaje& p); //capacidad de los objetos para seguir al personaje (espada)

	Objeto* operator[] (int i);

	int getNumero() { return numero; }
	int getIndex(Objeto* o) { return o->index; }
};