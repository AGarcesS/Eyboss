#pragma once
#include "Vector2D.h"
#include "Objeto.h"



class O_Gancho : public Objeto {
private:
    float longitud;
    bool feuer;
    Vector2D posorigen;

public:
    O_Gancho() : Objeto(GANCHO) {
        altura = ancho = 1;
        longitud = 15.0;
        velocidad.x = 0;
        velocidad.y = 0;
        posorigen.x = posicion.x = 0;
        posorigen.y = posicion.y = 0;
        orientacion = true;
        textura = "bin/texturas/gancho.png";
        index = 6;
        feuer = false;
    }
    virtual ~O_Gancho() {}


    void Inicializa();
    void Dibuja();
    void Mueve(float t);
    void SetPosOr(float ix, float iy);
    bool Limite();
    void SetF(bool f);
    bool GetF();
    Vector2D GetOr();

    void Ataca(Personaje& p);

    friend class Interaccion;
};