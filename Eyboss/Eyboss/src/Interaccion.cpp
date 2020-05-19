#include "Interaccion.h"
#include <math.h>

Interaccion::Interaccion() {

}

bool Interaccion::Colision(Pared pa, Vector2D pos, float r, float s = 0) { //Colisión como objeto sólido (proyectiles)
	if (s == 0)
		s = r;
	Vector2D punto1(pa.limite1.x, pa.limite2.y);
	Vector2D dir1;
	float d1 = pa.distanciap_r(punto1, pa.limite2, pos, &dir1) - r;                      //     p1.--------------------------.limite2
                                                                                       //       |                          | 
	Vector2D punto2(pa.limite2.x, pa.limite1.y);                                         //       |                          | 
	Vector2D dir2;                                                                     //       |                          |  
	float d2 = pa.distanciap_r(pa.limite1, punto2, pos, &dir2) - r;                  //       |                          |  
																					   //limite1.--------------------------.p2
	Vector2D dir3;
	float d3 = pa.distanciap_r(punto1, pa.limite1, pos, &dir3) - s;

	Vector2D dir4;
	float d4 = pa.distanciap_r(pa.limite2, punto2, pos, &dir4) - s;

	if ((d1 <= 0.0f) || (d2 <= 0.0f) || (d3 <= 0.0f) || (d4 <= 0.0f)) {
		return true;
	}
	else
		return false;
}

bool Interaccion::Colision(Personaje& p, Pared pa) {

	bool colision = false;

	Vector2D punto1(pa.limite1.x, pa.limite2.y);
	Vector2D dir1;
	float d1 = pa.distanciap_r(punto1, pa.limite2, p.posicion, &dir1) - p.altura / 2;               
	if ((d1 <= 0) && (pa.limite1.x - p.ancho / 2 < p.posicion.x < pa.limite2.x + p.ancho / 2)) {
		p.posicion.y = pa.limite2.y + p.altura / 2;
		p.velocidad.y = 0.0f;
		p.aceleracion.y = 0.0f;
		p.on = true;
		colision = true;
	}
	else {
		p.aceleracion.y = -9.8f;
		colision = false;
	}		
																					   
	Vector2D punto2(pa.limite2.x, pa.limite1.y);                                        
	Vector2D dir2;                                                                     
	float d2 = pa.distanciap_r(pa.limite1, punto2, p.posicion, &dir2) - p.altura / 2;
	if ((d2 <= 0) && (pa.limite1.x - p.ancho / 2 < p.posicion.x < pa.limite2.x + p.ancho / 2)) {
		p.posicion.y = pa.limite1.y - p.altura / 2;
		p.velocidad.y = 0.0f;
		p.aceleracion.y = -9.8f;
		colision = true;
	}
																					  
	Vector2D dir3;
	float d3 = pa.distanciap_r(punto1, pa.limite1, p.posicion, &dir3) - p.ancho / 2;
	if ((d3 <= 0) && (p.posicion.x > pa.limite1.x - p.ancho / 2)) {
		p.posicion.x = pa.limite1.x - p.ancho / 2;
		p.velocidad.x = p.aceleracion.x = 0.0f;
		p.aceleracion.y = -9.8f;
		colision = true;
	}

	Vector2D dir4;
	float d4 = pa.distanciap_r(pa.limite2, punto2, p.posicion, &dir4) - p.ancho / 2;
	if ((d4 <= 0) && (p.posicion.x < pa.limite2.x + p.ancho / 2)){
		p.posicion.x = pa.limite2.x + p.ancho / 2;
		p.velocidad.x = p.aceleracion.x = 0.0f;
		p.aceleracion.y = -9.8f;
		colision = true;
	}
	return colision;
}

bool Interaccion::Colision(Personaje& p, Caja c) {

	bool colision = false;

	if ((p.posicion.y - p.altura / 2) < c.suelo.limite2.y) {
		p.posicion.y = c.suelo.limite2.y + p.altura / 2;
		p.on = true;
		colision = true;
	}
	if ((p.posicion.y + p.altura / 2) > c.techo.limite1.y) {
		p.posicion.y = c.techo.limite1.y - p.altura / 2;
		colision = true;
	}
	if ((p.posicion.x + p.ancho / 2) > c.pared_dcha.limite1.x) {
		p.posicion.x = c.pared_dcha.limite1.x - p.ancho / 2;
		p.velocidad.x *= -1;
		colision = true;
	}

	if ((p.posicion.x - p.ancho / 2) < c.pared_izq.limite2.x) {
		p.posicion.x = c.pared_izq.limite2.x + p.ancho / 2;
		p.velocidad.x *= -1;
		colision = true;
	}		
	return colision;
}

bool Interaccion::Colision(Personaje p, Bonus b) {
	Pared aux;
	aux.SetPos(p.posicion.x - p.ancho / 2, p.posicion.y + p.altura / 2, p.posicion.x + p.ancho / 2, p.posicion.y - p.altura / 2);
	return Interaccion::Colision(aux, b.posicion, b.lado);
}

bool Interaccion::Colision(Disparo &d, Pared pa) {

	if (Colision(pa, d.posicion, d.radio)) {
		d.SetVel(0.0f, 0.0f);
		return true;
	}		
	else
		return false;
}

bool Interaccion::Colision(Disparo &d, Caja c) {
	if (Colision(d, c.techo) || Colision(d, c.suelo) || Colision(d, c.pared_izq) || Colision(d, c.pared_dcha))
		return true;
	else
		return false;
}