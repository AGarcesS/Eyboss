#pragma once
#include "Personaje.h"
#include "Purk.h"
#include "Troll.h"
#include "Veloz.h"
#include "ListaEnemigos.h"

class FactoryEnemigos {
public:
	void Crear(Personaje::enemigos n, ListaEnemigos& l, float px = 0, float py = 0, float vix = 0, float viy = 0) {
		switch (n) {
		case Personaje::PURK:
		{
			Purk* purk = new Purk();
			purk->SetPos(px, py);
			purk->SetVelIni(vix, viy);
			l.Agregar(purk);
			break;
		}
		case Personaje::VELOZ:
		{
			Veloz* veloz = new Veloz();
			veloz->SetPos(px, py);
			veloz->SetVelIni(vix, viy);
			l.Agregar(veloz);
			break;
		}
		case Personaje::TROLL:
			Troll* troll = new Troll();
			troll->SetPos(px, py);
			troll->SetVelIni(vix, viy);
			l.Agregar(troll);
			break;
		}

	}

};