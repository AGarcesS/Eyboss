#pragma once
#include "Objeto.h"
#include "ListaObjetos.h"
#include "ListaDisparos.h"
#include "O_Espada.h"

class FactoryObjetos {
public:
	void Crear(int n, ListaObjetos& l) {
		switch (n) {
		case 1:
		{
			ListaDisparos* obj = new ListaDisparos();
			l.Agregar(obj);
			obj->Inicializa();
			break;
		}
		/*case 2:
		{
			Objeto* obj = new O_Espada();
			l.Agregar(obj);
			obj->Inicializa();
			break;
		}		*/	
		}
	}
};