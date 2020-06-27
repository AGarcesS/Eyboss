#pragma once
#include "ETSIDI.h"
#include "Objeto.h"
#include "Personaje.h"

class O_Espada : public Objeto {
public:
	O_Espada() :Objeto(Objeto::ESPADA) {
		altura = 1;
		ancho = 1;
		posicion.x = 0;
		posicion.y = 0;
		tiempo0 = 0;
		m_tiempo = false;
		m_golpe = false;
		orientacion = true;
		textura = "bin/texturas/espada.png";
		index = 2;
	}
	virtual ~O_Espada() {}

	void Inicializa();
	void Dibuja();
	Vector2D GetPos();
	void SetPos(float ex, float ey);

	void Seguir(Personaje& p);
	void Ataca(Personaje& p);
	void Colision(ListaEnemigos& l);

	friend class Interaccion;
private:
	bool m_golpe;
};