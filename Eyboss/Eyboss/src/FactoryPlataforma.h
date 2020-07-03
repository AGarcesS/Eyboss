#pragma once
#include "ListaPlataformas.h"
#include "Pared.h"
#include "PlataformaSalto.h"
#include "PlataformaVelocidad.h"
#include "Fondo.h"
#include "ParedPuerta.h"

class FactoryPlataforma {
public:
	void Crear(Pared::plataformas n, ListaPlataformas& l, float lim1, float p1, float lim2, float p2, float f = 0.0f, float k = 1) {
		switch (n) {
		case Pared::NORMAL:
		{
			Pared* obj = new Pared(Pared::NORMAL);
			obj->SetPos(lim1, p1, lim2, p2, f);
			obj->SetK(k);
			l.Agregar(obj);
			break;
		}
		case Pared::SALTO:
		{
			PlataformaSalto* obj = new PlataformaSalto();
			obj->SetPos(lim1, p1, lim2, p2, f);
			obj->SetK(k);
			l.Agregar(obj);
			break;
		}
		case Pared::VELOCIDAD:
		{
			PlataformaVelocidad* obj = new PlataformaVelocidad();
			obj->SetPos(lim1, p1, lim2, p2, f);
			obj->SetK(k);
			l.Agregar(obj);
			break;
		}
		case Pared::FONDO:
		{
			Fondo* obj = new Fondo();
			obj->SetPos(lim1, p1, lim2, p2, f);
			l.Agregar(obj);
			break;
		}
		case Pared::PUERTA:
		{
			ParedPuerta* obj = new ParedPuerta();
			obj->SetPos(lim1, p1, lim2, p2, f);
			obj->SetK(k);
			l.Agregar(obj);
			break;
		}
		}
	}
};
