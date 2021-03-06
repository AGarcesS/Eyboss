#include "Interaccion.h"
#include <math.h>

Interaccion::Interaccion() {

}

bool Interaccion::Colision(Pared &pa, Vector2D pos, float r, float s) { //Colisi�n de dos rect�ngulos (r=altura, s=ancho)
	if (s == 0)
		s = r;
	Vector2D punto1(pa.limite1.x, pa.limite2.y);
	Vector2D punto2(pa.limite2.x, pa.limite1.y);

	Vector2D dir1;
	float d1 = pa.distanciap_r(punto1, pa.limite2, pos, &dir1) - r;                    //     p1.--------------------------.limite2
                                                                                       //       |                          | 
	                                                                                   //       |                          | 
	Vector2D dir2;                                                                     //       |                          |  
	float d2 = pa.distanciap_r(pa.limite1, punto2, pos, &dir2) - r;                    //       |                          |  
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

bool Interaccion::Colision(Personaje& p, Pared &pa) {

	bool colision = false;
	bool colisionarriba = false;
	int d_caida = 0; //da�o ca�da

	Vector2D punto1(pa.limite1.x, pa.limite2.y);
	Vector2D punto2(pa.limite2.x, pa.limite1.y);

	if (p.velocidad.y < -15 && p.GetMovimiento())
		d_caida = -p.velocidad.y * 0.2; //da�o de ca�da propocional a esta

	Vector2D dir1;  //colisi�n con el segmento punto1, limite2
	float d1 = pa.distanciap_r(punto1, pa.limite2, p.posicion, &dir1) - p.altura / 2;
	if ((d1 <= 0) && (pa.limite1.x - p.ancho / 2 < p.posicion.x < pa.limite2.x + p.ancho / 2) && ((p.posicion.y - p.altura / 2 + 0.2 > pa.limite2.y) || (p.velocidad.y < -5))) {
		p.posicion.y = pa.limite2.y + p.altura / 2;
		if (p.GetMovimiento()) {
			p.velocidad.y = 0.0f;
		}
		p.aceleracion.y = 0.0f;
		p.on = true;
		colision = true;
		colisionarriba = true;
	}
	else {
		if (p.GetMovimiento()) {
			p.aceleracion.y = -9.8f;
		}
		colision = false;
		colisionarriba = false;
	}

	Vector2D dir2; //colisi�n con el segmento limite1, punto 2                                                                      
	float d2 = pa.distanciap_r(pa.limite1, punto2, p.posicion, &dir2) - p.altura / 2;
	if ((d2 <= 0) && (pa.limite1.x - p.ancho / 2 < p.posicion.x < pa.limite2.x + p.ancho / 2)) {
		p.posicion.y = pa.limite1.y - p.altura / 2;
		p.velocidad.y = 0.0f;
		p.aceleracion.y = -9.8f;
		p.on = false;
		colision = true;
		colisionarriba = false;
	}
																					  
	Vector2D dir3; //colisi�n con el segmento punto1, limite1
	float d3 = pa.distanciap_r(punto1, pa.limite1, p.posicion, &dir3) - p.ancho / 2;
	if ((d3 <= 0) && (p.posicion.x > pa.limite1.x - p.ancho / 2)) {
		p.posicion.x = pa.limite1.x - p.ancho / 2;
		if (p.GetTipo() != Personaje::PROTAGONISTA)
			p.velocidad.x *= -1;		
		p.aceleracion.x = 0.0f;
		p.aceleracion.y = -9.8f;
		p.on = false;
		colision = true;
		colisionarriba = false;
		
	}

	Vector2D dir4; //colision con el segmento limite2, punto2
	float d4 = pa.distanciap_r(pa.limite2, punto2, p.posicion, &dir4) - p.ancho / 2;
	if ((d4 <= 0) && (p.posicion.x < pa.limite2.x + p.ancho / 2)){
		p.posicion.x = pa.limite2.x + p.ancho / 2;
		if (p.GetTipo() != Personaje::PROTAGONISTA)
			p.velocidad.x *= -1;
		p.aceleracion.x = 0.0f;
		p.aceleracion.y = -9.8f;
		p.on = false;
		colision = true;
		colisionarriba = false;
	}
	
	if (pa.GetTipo() == Pared::SALTO) { //para la plataforma de salto no hay da�o por ca�da y se aumenta la velocidad en y
		if (colisionarriba) {
			p.velocidad.y = 11;
			p.aceleracion.y = -9.8f;
			p.on = false;
			d_caida = 0;
		}
	}	

	if (pa.GetTipo() == Pared::VELOCIDAD) { //para la plataforma de velocidad se aumenta en valor absoluto la velocidad en x
		if (colisionarriba) {
			if (p.GetOrientacion())
				p.SetVel(p.GetVel().x + 1, p.GetVel().y);
			else
				p.SetVel(p.GetVel().x - 1, p.GetVel().y);
		}
	}

	if (pa.GetTipo() == Pared::PUERTA) { //para la puerta se cambia de nivel con el requisito de colisi�n o colisi�n y recoger llaves
		if (Global::nivel == 1 || Global::nivel == 2) {
			if (p.GetTipo() == Personaje::PROTAGONISTA && colision)
				Global::cambio_nivel = true;
		}
		if (Global::nivel == 3) {
			if (p.GetTipo() == Personaje::PROTAGONISTA && colision && Global::llave == 3)
				Global::cambio_nivel = true;
		}		
	}		

	if (colision)
		p.vida -= d_caida;
	if (!colision && p.velocidad.y < 0)
		p.on = false;
	
	return colision;
}

bool Interaccion::Colision(Disparo &d, Pared &pa) {

	return Colision(pa, d.posicion, d.radio);
}

bool Interaccion::Colision(Disparo& d, Personaje& p) {

	if (abs(d.posicion.x - p.posicion.x) < (d.radio * 1.5 + p.ancho) / 2 && abs(d.posicion.y - p.posicion.y) < (d.radio + p.ancho) / 2)
		return true;
	return false;
}

bool Interaccion::Colision(Bonus& b, Personaje& p) {

	if (abs(b.posicion.x - p.posicion.x) < (b.lado + p.ancho) / 2 && abs(b.posicion.y - p.posicion.y) < (b.lado + p.ancho) / 2)
		return true;
	return false;
}

bool Interaccion::Colision(Personaje& p1, Personaje& p2) {			//p1 enemigo, p2 protagonista
	
	if (!p2.m_da�o) {
		if (abs(p1.posicion.y - p2.posicion.y) < (p1.altura + p2.altura) / 2 && abs(p1.posicion.x - p2.posicion.x) < (p1.ancho + p2.ancho) / 2) {
			p2.tiempo0 = Global::tiempo;
			p2.m_da�o = true;
			p2.m_parpadeo = true;
			return true;
		}
	}

	if ((Global::tiempo - p2.tiempo0) / 40 > 2)
	{
		p2.tiempo0 = 0;
		p2.m_da�o = false;
		p2.m_parpadeo = false;
	}

	return false;
}

bool Interaccion::Cercania(Personaje& p1, Personaje& p2) {

	bool derecha = false;

	if ((p2.posicion.x - p1.posicion.x) > 0)
		derecha = true;							// p2 a la derecha de p1

	if ((p2.posicion - p1.posicion).modulo() < p1.dist_seguimiento) {

		if (derecha)
			p1.velocidad.x = p1.vel_seguimiento.x;
		else
			p1.velocidad.x = -p1.vel_seguimiento.x;

		return true;
	}

	if (p1.velocidad.x * p1.vel_ini.x >= 0)		//Signos iguales o si una de ellas es 0
		p1.velocidad.x = p1.vel_ini.x;
	if (p1.velocidad.x * p1.vel_ini.x < 0)
		p1.velocidad.x = -p1.vel_ini.x;			//Signos opuestos
	return false;
}

bool Interaccion::NoCaer(Personaje& p, Pared& pa) {
	Vector2D punto1(pa.limite1.x, pa.limite2.y);
	Vector2D dir1;
	float d1 = pa.distanciap_r(punto1, pa.limite2, p.posicion, &dir1) - (p.altura + 0.1) / 2;

	if ((d1 <= 0) && (pa.limite1.x + -p.ancho / 2 < p.posicion.x < pa.limite2.x + p.ancho / 2) && ((p.posicion.y - p.altura / 2 + 0.1 > pa.limite2.y) || (p.velocidad.y < -5))) {
		if (abs(p.posicion.x - (pa.limite2.x + pa.limite1.x) / 2) > (pa.limite2.x - pa.limite1.x) / 2 - p.ancho / 2)
		{
			p.velocidad.x = -p.velocidad.x;
			return 1;
		}
		return 0;
	}

	return 0;
}

bool Interaccion::Colision(O_Espada& e, Personaje& p) {
	
	if ((Global::tiempo - e.tiempo0) / 40 < 0.5 && Global::tiempo / 40 > 0.5) {
		if (abs(p.posicion.y - e.posicion.y) < (p.altura + e.altura) / 2 && abs(p.posicion.x - e.posicion.x) < (p.ancho + e.ancho) / 2) {
			return true;
		}
	}

	return false;
}


int Interaccion::Colision(DisparoGancho& dg, Pared pa, Personaje& nyes) {
	if (Colision(pa, dg.posicion, 0.1))
	{
		dg.SetPared(true);
		dg.SetVel(0, 0);
		nyes.SetAcel(0.0f, 0.0f);
		if (nyes.GetOrientacion())
			nyes.SetVel(5.0f, 5.0f);
		else
			nyes.SetVel(-5.0f, 5.0f);
		dg.SetF(false);
		dg.SetPosOr(nyes.GetPos().x, nyes.GetPos().y);
		return 1;
	}
	else if ((dg.posicion - nyes.posicion).modulo() >= dg.longitud) {
		dg.SetF(false);
		if (nyes.GetOrientacion())
			dg.SetVel(-5, -5);
		else
			dg.SetVel(5, -5);
		nyes.SetAcel(0.0f, 0.0f);
		nyes.SetPos(dg.GetOr().x, dg.GetOr().y);
		return 2;
	}
	else
		return 0;
}