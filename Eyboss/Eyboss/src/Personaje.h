#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"

class Personaje {
public:
	enum enemigos { PROTAGONISTA = 0, PURK, VELOZ, TROLL, HADA };
protected:
	enemigos tipo;
	float altura; 
	float ancho;
	bool orientacion; //marca de orientación (true: derecha, false: izquierda)
	bool orien_ini; //orientación inicial
	bool on; //marca de salto (true: puede saltar, false: no puede saltar)
	float salto; //potencia de salto
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D vel_ini; //velocidad inicial
	Vector2D vel_seguimiento; //velocidad del personaje al perseguir al protagonista (solo enemigos)
	Vector2D aceleracion;
	const char* textura;
	int vida; //vida del personaje
	int daño; //daño que realiza el personaje (solo enemigos)
	int col; //columnas de animación del sprite
	float dist_seguimiento; //distancia a la que el personaje detecta al protagonista (solo enemigos)
	ETSIDI::SpriteSequence* animacion;               
	bool detencion;
	bool nogancho;

	bool m_daño; //marca de daño

	//gestión de tiempos
	bool m_parpadeo; //marca de parpadeo
	bool m_tiempo; //marca tiempo
	float tiempo0; //tiempo inicial

	int señal_ataque; //marca para permitir el uso de objetos (solo enemigos)
public:
	Personaje(enemigos e, float altura, float ancho, bool orientacion, bool orien_ini, bool on, float salto, const char* textura, int vida, int col, bool nogancho, bool m_daño,
		bool m_parpadeo, bool m_tiempo, float tiempo0, int señal_ataque = 0, int daño = 0, float dist_seguimiento = 0.0f) : tipo(e), altura(altura), ancho(ancho), orientacion(orientacion), orien_ini(orien_ini),
		on(on), salto(salto), posicion(posicion), velocidad(velocidad), vel_ini(vel_ini), vel_seguimiento(vel_seguimiento), aceleracion(aceleracion), textura(textura), vida(vida), col(col), detencion(detencion),
		nogancho(nogancho),	m_daño(m_daño), m_parpadeo(m_parpadeo), m_tiempo(m_tiempo), tiempo0(tiempo0), señal_ataque(señal_ataque), daño(daño), dist_seguimiento(dist_seguimiento) {}

	enemigos GetTipo() { return tipo; }
	virtual ~Personaje() {}


	//Interfaz de salida
	Vector2D GetPos();
	Vector2D GetVel();
	Vector2D GetVelIni();
	Vector2D GetAcel();
	float GetAltura();
	float GetAncho();
	float GetSalto();
	bool GetOn();
	bool GetOrientacion();
	bool GetOrienini();
	int GetVida();
	int GetDaño();
	int GetAtaque();
	bool GetMovimiento() { return nogancho; }

	//Interfaz de entrada
	void SetPos(float px, float py);
	void SetVel(float vx, float vy);
	void SetVelIni(float vix, float viy);
	void SetAcel(float ax, float ay);
	void SetSalto(float s);
	void SetOn(bool x);
	void SetOrientacion(bool ori);
	void SetOrienini(bool oriini);
	void SetVida(int v);
	void SetAtaque(int a);
	void SetMovimiento(bool d) { nogancho = d; }
	void SetTextura(const char* t);

	virtual void Dibuja();
	void Mueve(float t);
	void Inicializa();

	friend class Interaccion;
};