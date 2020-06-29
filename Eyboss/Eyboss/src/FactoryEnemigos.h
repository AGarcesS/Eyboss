#pragma once
#include "Personaje.h"
#include "Purk.h"
#include "Troll.h"
#include "Veloz.h"
#include "ListaEnemigos.h"
#include "FactoryObjetos.h"

class FactoryEnemigos {
public:
	void Crear(Personaje::enemigos n, ListaEnemigos& l, float px = 0, float py = 0, float vix = 0, float viy = 0, Objeto::objetos o = Objeto::OBJETO, ListaObjetos* l1 = 0) {
		FactoryObjetos objetos;
		switch (n) {
		case Personaje::PURK:
		{
			Purk* purk = new Purk();
			purk->SetPos(px, py);
			purk->SetVelIni(vix, viy);
			l.Agregar(purk);
			if (l1 != 0 && o != Objeto::OBJETO) {
				purk->SetAtaque(o);
				objetos.Crear(o, *l1);
			}
			purk->Inicializa();
			break;
		}
		case Personaje::VELOZ:
		{
			Veloz* veloz = new Veloz();
			veloz->SetPos(px, py);
			veloz->SetVelIni(vix, viy);
			l.Agregar(veloz);
			if (l1 != 0 && o != Objeto::OBJETO) {
				veloz->SetAtaque(o);
				objetos.Crear(o, *l1);
			}
			veloz->Inicializa();
			break;
		}
		case Personaje::TROLL:
			Troll* troll = new Troll();
			troll->SetPos(px, py);
			troll->SetVelIni(vix, viy);
			l.Agregar(troll);
			if (l1 != 0 && o != Objeto::OBJETO) {
				troll->SetAtaque(o);
				objetos.Crear(o, *l1);
			}
			troll->Inicializa();
			break;
		}
	}

};