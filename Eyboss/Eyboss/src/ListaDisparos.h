#pragma once
#define MAX_DISPAROS 50
#include "Disparo.h"
#include "Caja.h"
#include "Pared.h"
#include "Objeto.h"
#include "Personaje.h"
#include "ListaEnemigos.h"
#include "ListaPlataformas.h"
#include "Interaccion.h"
#include "Global.h"

//class ListaDisparos :public Objeto {
//private:
//	Disparo* lista[MAX_DISPAROS];
//	int numero;
//public:
//
//	ListaDisparos(Disparo &d) :Objeto(TIRACHINAS) {
//		numero = 0;
//		for (int i = 0; i < MAX_DISPAROS; i++)
//			lista[i] = 0;
//		index = 1;
//	}
//
//	/*ListaDisparos(){
//		numero = 0;
//		for (int i = 0; i < MAX_DISPAROS; i++)
//			lista[i] = 0;
//		index = 1;
//	}*/
//
//	/*ListaDisparos(){
//		numero = 0;
//		for (int i = 0; i < MAX_DISPAROS; i++)
//			lista[i] = 0;
//		index = 1;
//	}*/
//
//	virtual ~ListaDisparos() {}
//
//	bool Agregar(Disparo* d);
//	void DestruirContenido();
//	void Eliminar(int index);
//	void Eliminar(Disparo* d);
//	Disparo* operator [] (int i);
//	void Inicializa();
//	void Mueve(float t);
//	void Dibuja();
//
//	Disparo* Colision(Pared p);
//
//	int getNumero() { return numero; }
//
//	void Ataca(Personaje &p);
//	void Colision(ListaPlataformas& l);
//	void Colision(ListaEnemigos& l);
//	void Colision(Caja &c);	
//};

template<class T, int ind, Objeto::objetos tip> class ListaDisparos :public Objeto {
private:
	T *lista[MAX_DISPAROS];
	int numero;
	int municion;
public:
	ListaDisparos() :Objeto(tip) {
		numero = 0;
		for (int i = 0; i < MAX_DISPAROS; i++)
			lista[i] = 0;
		index = ind;
		municion = 0;
	}

	virtual ~ListaDisparos() {}

	bool Agregar(T* d) {
		if (tip == Objeto::TIRACHINAS)
			municion = Global::municion;
		if (tip == Objeto::TIRACHINAS_LENTO)
			municion = Global::municionlenta;
		if (tip == Objeto::TIRACHINAS_RAPIDO)
			municion = Global::municionrapida;
		if (numero < municion) {
			municion--;
			lista[numero] = d;
			ETSIDI::play("bin/sonidos/shoot.wav");
			numero++;			
			if (tip == Objeto::TIRACHINAS)
				Global::municion = municion;
			if (tip == Objeto::TIRACHINAS_LENTO)
				Global::municionlenta = municion;
			if (tip == Objeto::TIRACHINAS_RAPIDO)
				Global::municionrapida = municion;
			return true;
		}
		else
			return false;
	}

	void DestruirContenido() {
		for (int i = 0; i < numero; i++)
			delete lista[i];
		numero = 0;
		municion = 0;
	}

	void Eliminar(int index) {
		if ((index < 0 || index >= numero))
			return;
		delete lista[index];
		numero--;
		for (int i = index; i < numero; i++)
			lista[i] = lista[i + 1];
	}

	void Eliminar(T* d) {
		for (int i = 0; i < numero; i++) {
			if (lista[i] == d) {
				Eliminar(i);
				return;
			}
		}
	}

	void Inicializa() {
		for (int i = 0; i < numero; i++)
			lista[i]->Inicializa();
	}

	void Mueve(float t) {
		for (int i = 0; i < numero; i++)
			lista[i]->Mueve(t);
	}

	void Dibuja() {
		for (int i = 0; i < numero; i++)
			lista[i]->Dibuja();
	}

	T* Colision(Pared p) {
		for (int i = 0; i < numero; i++) {
			if (Interaccion::Colision(*lista[i], p))
				return lista[i];
		}
		return 0;
	}

	T* operator [] (int i) {
		if (i >= numero)
			i = numero - 1;
		if (i < 0)
			i = 0;
		return lista[i];
	}

	void Ataca(Personaje& p) {
		T* d = new T();
		d->SetPos(p.GetPos().x, p.GetPos().y);
		if (p.GetOrientacion())
			d->SetVel(7.0f, 0.0f);
		else
			d->SetVel(-7.0f, 0.0f);
		Agregar(d);
		Inicializa();		
	}

	void Colision(ListaEnemigos& l) {
		for (int i = 0; i < l.getNumero(); i++) {
			for (int j = 0; j < numero; j++) {
				if (Interaccion::Colision(*lista[j], *l[i])) {
					if (l[i]->GetVida() > 0) {
						l[i]->SetVida(-1);
					}
					else {
						l.Eliminar(l[i]);
					}
					Eliminar(lista[j]);
					break;
				}
			}
		}
	}

	void Colision(ListaPlataformas& l) {
		for (int i = 0; i < l.getNumero(); i++) {
			T* aux = Colision(*l[i]);
			if (aux != 0)
				Eliminar(aux);
		}
	}
};