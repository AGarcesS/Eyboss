#pragma once
class Global {
private:
	Global() {}
public:
	static float tiempo;
	static bool reset;

	static int bajas;
	static int vida;

	static int municion;
	static int municionlenta;
	static int municionrapida;

	static bool cambio_nivel;
};