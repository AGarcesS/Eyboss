//#include "ListaDisparos.h"
//#include "Interaccion.h"
//#include "ETSIDI.h"
//#include "Global.h"
//
//bool ListaDisparos::Agregar(Disparo* d) {
//	if (numero < MAX_DISPAROS) {
//		lista[numero] = d;
//		numero++;
//		for (int i = 0; i < numero; i++)
//		{
//			if (lista[i] == d)
//				return false;
//			else
//				return true;
//		}
//	}
//	else
//		return false;
//}
//
//void ListaDisparos::DestruirContenido() {
//	for (int i = 0; i < numero; i++)
//		delete lista[i];
//	numero = 0;
//}
//
//void ListaDisparos::Eliminar(int index) {
//	if ((index < 0 || index >= numero))
//		return;
//	delete lista[index];
//	numero--;
//	for (int i = index; i < numero; i++)
//		lista[i] = lista[i + 1];
//}
//
//void ListaDisparos::Eliminar(Disparo* d) {
//	for (int i = 0; i < numero; i++) {
//		if (lista[i] == d) {
//			Eliminar(i);
//			return;
//		}
//	}
//}
//
//void ListaDisparos::Inicializa() {
//	for (int i = 0; i < numero; i++)
//		lista[i]->Inicializa();
//}
//
//void ListaDisparos::Mueve(float t){
//	for (int i = 0; i < numero; i++)
//		lista[i]->Mueve(t);	
//}
//
//void ListaDisparos::Dibuja() {
//	for (int i = 0; i < numero; i++)
//		lista[i]->Dibuja();
//}
//
//Disparo* ListaDisparos::Colision(Pared p) {
//	for (int i = 0; i < numero; i++) {
//		if (Interaccion::Colision(*lista[i], p))
//			return lista[i];
//	}		
//	return 0;
//}
//
//Disparo* ListaDisparos::operator [] (int i) {
//	if (i >= numero)
//		i = numero - 1;
//	if (i < 0)
//		i = 0;
//	return lista[i];
//}
//
//void ListaDisparos::Ataca(Personaje& p) {
//	Disparo* d = new Disparo();
//	d->SetPos(p.GetPos().x, p.GetPos().y);
//	if (p.GetOrientacion())
//		d->SetVel(7.0f, 0.0f);
//	else
//		d->SetVel(-7.0f, 0.0f);
//	Agregar(d);
//	Inicializa();
//	ETSIDI::play("bin/sonidos/shoot.wav");
//}
//
//void ListaDisparos::Colision(ListaEnemigos& l) {
//	for (int i = 0; i < l.getNumero(); i++) {
//		for (int j = 0; j < numero; j++) {
//			if (Interaccion::Colision(*lista[i], *l[i])) {
//				if (l[i]->GetVida() > 0) {
//					l[i]->SetVida(-1);
//				}
//				else {
//					l.Eliminar(l[i]);
//				}
//				Eliminar(lista[j]);
//				break;
//			}
//		}		
//	}
//}
//
//void ListaDisparos::Colision(ListaPlataformas& l) {
//	for (int i = 0; i < l.getNumero(); i++) {
//		Disparo* aux = Colision(*l[i]);
//		if (aux != 0)
//			Eliminar(aux);
//	}
//}
//
//void ListaDisparos::Colision(Caja &c) {
//	for (int i = 0; i < numero; i++) {
//		if (Interaccion::Colision(*lista[i], c))
//			Eliminar(lista[i]);
//	}
//}
//
