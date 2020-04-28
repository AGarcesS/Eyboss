#include "Interaccion.h"
#include <math.h>

Interaccion::Interaccion() {

}

bool Interaccion::Colision(Pared p, Vector2D pos, float r, float s = 0.0f) { //Colisión como objeto sólido (proyectiles)
	Vector2D punto1(p.limite1.x, p.limite2.y);
	Vector2D dir1;
	float d1 = p.distanciap_r(punto1, p.limite2, pos, &dir1) - r;                      //     p1.--------------------------.limite2
                                                                                       //       |                          | 
	Vector2D punto2(p.limite2.x, p.limite1.y);                                         //       |                          | 
	Vector2D dir2;                                                                     //       |                          |  
	float d2 = p.distanciap_r(p.limite1, punto2, pos, &dir2) - r + s;                  //       |                          |  
																					   //limite1.--------------------------.p2
	Vector2D dir3;
	float d3 = p.distanciap_r(punto1, p.limite1, pos, &dir3) - r + s;

	Vector2D dir4;
	float d4 = p.distanciap_r(p.limite2, punto2, pos, &dir4) - r;

	if ((d1 <= 0.0f) || (d2 <= 0.0f) || (d3 <= 0.0f) || (d4 <= 0.0f)) {
		return true;
	}
	else
		return false;
}

bool Interaccion::Colision(Protagonista& h, Pared p) {

	Vector2D punto1(p.limite1.x, p.limite2.y);
	Vector2D dir1;
	float d1 = p.distanciap_r(punto1, p.limite2, h.posicion, &dir1) - h.altura / 2;               
	if ((d1 <= 0) && (p.limite1.x - h.ancho / 2 < h.posicion.x < p.limite2.x + h.ancho / 2)) {
		h.posicion.y = p.limite2.y + h.altura / 2;
		h.velocidad.y = 0.0f;
		h.aceleracion.y = 0.0f;
		h.on = true;
	}
	else {
		h.aceleracion.y = -9.8f;
	}		
																					   
	Vector2D punto2(p.limite2.x, p.limite1.y);                                        
	Vector2D dir2;                                                                     
	float d2 = p.distanciap_r(p.limite1, punto2, h.posicion, &dir2) - h.altura / 2;
	if ((d2 <= 0) && (p.limite1.x - h.ancho / 2 < h.posicion.x < p.limite2.x + h.ancho / 2)) {
		h.posicion.y = p.limite1.y - h.altura / 2;
		h.velocidad.y = 0.0f;
		h.aceleracion.y = -9.8f;
	}
																					  
	Vector2D dir3;
	float d3 = p.distanciap_r(punto1, p.limite1, h.posicion, &dir3) - h.ancho / 2;
	if ((d3 <= 0) && (h.posicion.x > p.limite1.x - h.ancho / 2)) {
		h.posicion.x = p.limite1.x - h.ancho / 2;
		h.velocidad.x = h.aceleracion.x = 0.0f;
		h.aceleracion.y = -9.8f;
	}

	Vector2D dir4;
	float d4 = p.distanciap_r(p.limite2, punto2, h.posicion, &dir4) - h.ancho / 2;
	if ((d4 <= 0) && (h.posicion.x < p.limite2.x + h.ancho / 2)){
		h.posicion.x = p.limite2.x + h.ancho / 2;
		h.velocidad.x = h.aceleracion.x = 0.0f;
		h.aceleracion.y = -9.8f;
	}

	if ((d1 <= 0.0f) || (d2 <= 0.0f) || (d3 <= 0.0f) || (d4 <= 0.0f)) {
		return true;
	}
	else
		return false;
}

bool Interaccion::Colision(Protagonista& h, Caja c) {
	if ((h.posicion.y - h.altura / 2) < c.suelo.limite2.y) {
		h.posicion.y = c.suelo.limite2.y + h.altura / 2;
		h.on = true;
		return true;
	}
	else if ((h.posicion.y + h.altura / 2) > c.techo.limite1.y) {
		h.posicion.y = c.techo.limite1.y - h.altura / 2;
		return true;
	}
	else if ((h.posicion.x + h.ancho / 2) > c.pared_dcha.limite1.x) {
		h.posicion.x = c.pared_dcha.limite1.x - h.ancho / 2;
		return true;
	}

	else if ((h.posicion.x - h.ancho / 2) < c.pared_izq.limite2.x) {
		h.posicion.x = c.pared_izq.limite2.x + h.ancho / 2;
		return true;
	}		
	else
		return false;
}

bool Interaccion::Colision(Disparo &d, Pared p) {

	if (Colision(p, d.posicion, d.radio)) {
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