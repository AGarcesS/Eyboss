#pragma once
class Global {
private:
	Global() {}
public:
	static float tiempo;	
	static int bajas;
	static int vida;
	static int municion;
	static int municionlenta;
	static int municionrapida;
	static int nivel;
	static bool cambio_nivel; //marca de cambio de nivel
	static int llave;
};