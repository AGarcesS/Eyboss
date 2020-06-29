#pragma once
#define MAX_DISPAROS 50
#include "Disparo.h"
#include "Pared.h"
#include "Objeto.h"
#include "Personaje.h"
#include "ListaEnemigos.h"
#include "ListaPlataformas.h"
#include "Interaccion.h"
#include "Global.h"

template<class T, int ind, Objeto::objetos tip> class ListaDisparos :public Objeto {
private:
	T *lista[MAX_DISPAROS];
	int numero;

	int GetMunicion() {
		if (tip == Objeto::TIRACHINAS)
			return Global::municion;
		if (tip == Objeto::TIRACHINAS_LENTO)
			return Global::municionlenta;
		if (tip == Objeto::TIRACHINAS_RAPIDO)
			return Global::municionrapida;
	}

	void SetMunicion(int m) {
		if (tip == Objeto::TIRACHINAS)
			Global::municion = m;
		if (tip == Objeto::TIRACHINAS_LENTO)
			Global::municionlenta = m;
		if (tip == Objeto::TIRACHINAS_RAPIDO)
			Global::municionrapida = m;
	}

public:
	ListaDisparos() :Objeto(tip) {
		numero = 0;
		for (int i = 0; i < MAX_DISPAROS; i++)
			lista[i] = 0;
		index = ind;
	}

	virtual ~ListaDisparos() {}

	bool Agregar(T* d) {		
		if (numero < MAX_DISPAROS) {				
			lista[numero] = d;			
			numero++;		
			ETSIDI::play("bin/sonidos/shoot.wav");	
			return true;
		}
		else
			return false;
	}

	void DestruirContenido() {
		for (int i = 0; i < numero; i++)
			delete lista[i];
		numero = 0;
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
		if (p.GetTipo() == Personaje::PROTAGONISTA) {
			if (numero < GetMunicion()) {
				SetMunicion(GetMunicion() - 1);
				T* d = new T();
				d->SetPos(p.GetPos().x, p.GetPos().y);
				if (p.GetOrientacion())
					d->SetVel(d->GetRapidez(), 0.0f);
				else
					d->SetVel(-d->GetRapidez(), 0.0f);
				Agregar(d);
				Inicializa();
			}
		}
		else {
			T* d = new T();
			d->SetPos(p.GetPos().x, p.GetPos().y);
			if (p.GetVel().x > 0)
				d->SetVel(d->GetRapidez(), 0.0f);
			else
				d->SetVel(-d->GetRapidez(), 0.0f);
			Agregar(d);
			Inicializa();
		}
	}

	void Colision(Personaje& p) {
		for (int i = 0; i < numero; i++) {
			if (Interaccion::Colision(*lista[i], p)) {
				if (p.GetVida() > 0) {
					p.SetVida(-lista[i]->GetDamage());
				}
				Eliminar(lista[i]);
				break;
			}
		}
	}

	void Colision(ListaEnemigos& l) {
		for (int i = 0; i < l.getNumero(); i++) {
			for (int j = 0; j < numero; j++) {
				if (Interaccion::Colision(*lista[j], *l[i])) {
					if (l[i]->GetVida() > 0) {
						l[i]->SetVida(-lista[j]->GetDamage());
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

	void Colision(ListaPlataformas& l, Personaje* pe) {
		for (int i = 0; i < l.getNumero(); i++) {
			T* aux = Colision(*l[i]);
			if (aux != 0)
				Eliminar(aux);
		}
	}
};