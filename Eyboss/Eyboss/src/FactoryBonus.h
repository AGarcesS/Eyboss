#pragma once
#include "ListaBonus.h"
#include "Bonus.h"
#include "B_Espada.h"
#include "B_Gancho.h"
#include "B_Tirachinas.h"
#include "B_TirachinasLento.h"
#include "B_TirachinasRapido.h"
#include "Corazon.h"
#include "Llave.h"

class FactoryBonus {
public:
	void Crear(Bonus::bonus n, ListaBonus& l, float px = 0, float py = 0) {
		switch (n) {
		case Bonus::TIRACHINAS:
		{
			B_Tirachinas* bonus = new B_Tirachinas();
			l.Agregar(bonus);
			bonus->Inicializa();
			bonus->SetPos(px, py);
			break;
		}
		case Bonus::ESPADA:
		{
			B_Espada* bonus = new B_Espada();
			l.Agregar(bonus);
			bonus->Inicializa();
			bonus->SetPos(px, py);
			break;
		}
		case Bonus::CORAZON:
		{
			Corazon* bonus = new Corazon();
			l.Agregar(bonus);
			bonus->Inicializa();
			bonus->SetPos(px, py);
			break;
		}
		case Bonus::TIRACHINAS_LENTO:
		{
			B_TirachinasLento* bonus = new B_TirachinasLento();
			l.Agregar(bonus);
			bonus->Inicializa();
			bonus->SetPos(px, py);
			break;
		}
		case Bonus::TIRACHINAS_RAPIDO:
		{
			B_TirachinasRapido* bonus = new B_TirachinasRapido();
			l.Agregar(bonus);
			bonus->Inicializa();
			bonus->SetPos(px, py);
			break;
		}
		case Bonus::GANCHO:
		{
			B_Gancho* bonus = new B_Gancho();
			l.Agregar(bonus);
			bonus->Inicializa();
			bonus->SetPos(px, py);
			break;
		}
		case Bonus::LLAVE:
		{
			Llave* bonus = new Llave();
			l.Agregar(bonus);
			bonus->Inicializa();
			bonus->SetPos(px, py);
			break;
		}
		}
	}
};