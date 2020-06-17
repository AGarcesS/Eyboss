#pragma once
#include "ListaPlataformas.h"
#include "Pared.h"
#include "PlataformaSalto.h"
#include "PlataformaVelocidad.h"

class FactoryPlataforma {
public:
	void Crear(Pared::plataformas n, ListaPlataformas& l, float lim1, float p1, float lim2, float p2) {
		switch (n) {
		case Pared::NORMAL:
		{
			Pared* obj = new Pared(Pared::NORMAL);
			obj->SetPos(lim1, p1, lim2, p2);
			l.Agregar(obj);
			break;
		}
		case Pared::SALTO:
		{
			PlataformaSalto* obj = new PlataformaSalto();
			obj->SetPos(lim1, p1, lim2, p2);
			l.Agregar(obj);
			break;
		}
		case Pared::VELOCIDAD:
			PlataformaVelocidad* obj = new PlataformaVelocidad();
			obj->SetPos(lim1, p1, lim2, p2);
			l.Agregar(obj);
			break;
		}
	}
};
