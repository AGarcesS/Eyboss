#pragma once
#include "ETSIDI.h"
#include "Protagonista.h"
#include "ListaObjetos.h"

class Interfaz {
private:
	ETSIDI::Sprite* corazon1, * corazon2, * corazon3, * corazon4, * corazon5,
		* corazon_m1, * corazon_m2, * corazon_m3, * corazon_m4, * corazon_m5,
		* corazon_v1, * corazon_v2, * corazon_v3, * corazon_v4, * corazon_v5,
		* tirachinas, * tirachinas_rapido, * tirachinas_lento, * espada, * gancho,
		* bajas, * tiempo, * llave;

public:
	void ImprimeJuego(Protagonista& p, ListaObjetos& l);
	void Inicializa();
};