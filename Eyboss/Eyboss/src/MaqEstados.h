#pragma once
#include "Mundo.h"

class MaqEstados {
protected:
	enum Estado { INICIO, JUEGO, FIN, GAMEOVER, PAUSA };
	Estado estado;
public:
	MaqEstados();
	virtual ~MaqEstados() {}

	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void TeclaMantenida(unsigned char key);
	void Mueve();
	void Dibuja();
protected:
	Mundo mundo;
};