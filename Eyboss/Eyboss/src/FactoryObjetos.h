#pragma once
#include "Objeto.h"
#include "ListaObjetos.h"
#include "ListaDisparos.h"
#include "O_Espada.h"
#include "O_Gancho.h"
#include "DisparoLento.h"
#include "DisparoRapido.h"

class FactoryObjetos {
public:
	void Crear(int n, ListaObjetos& l) {
		switch (n) {
		case 1:
		{
			ListaDisparos<Disparo, 1, Objeto::TIRACHINAS> *obj;
			obj = new ListaDisparos<Disparo, 1, Objeto::TIRACHINAS>();
			//ListaDisparos* obj = new ListaDisparos();
			l.Agregar(obj);
			obj->Inicializa();
			break;
		}
		case 2:
		{
			O_Espada* aux = new O_Espada();
			l.Agregar(aux);
			aux->Inicializa();
			break;
		}
		case 4:
		{
			ListaDisparos<DisparoLento, 5, Objeto::TIRACHINAS_LENTO>* obj;
			obj = new ListaDisparos<DisparoLento, 5, Objeto::TIRACHINAS_LENTO>();
			l.Agregar(obj);
			obj->Inicializa();
			break;
		}
		case 5:
		{
			ListaDisparos<DisparoRapido, 4, Objeto::TIRACHINAS_RAPIDO>* obj;
			obj = new ListaDisparos<DisparoRapido, 4, Objeto::TIRACHINAS_RAPIDO>();	
			l.Agregar(obj);
			obj->Inicializa();
			break;
		}
		case 6:
			O_Gancho * aux = new O_Gancho();
			l.Agregar(aux);
			aux->Inicializa();
			break;
		}
	}
};