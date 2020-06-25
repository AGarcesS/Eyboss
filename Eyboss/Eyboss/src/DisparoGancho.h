#pragma once
#include "Vector2D.h"
#include "Disparo.h"



class DisparoGancho : public Disparo {
private:
    bool feuer;
    Vector2D posorigen;
    bool orientacion;
public:
    DisparoGancho() {
        radio = 1;
        longitud = 15.0;
        velocidad.x = 0;
        velocidad.y = 0;
        posorigen.x = posicion.x = 0;
        posorigen.y = posicion.y = 0;
        orientacion = true;
        textura = "bin/texturas/gancho.png";
    }
    virtual ~DisparoGancho() {}


    void Dibuja();
    void Mueve(float t);
    void SetPosOr(float ix, float iy);
    bool Limite();
    void SetF(bool f);
    bool GetF();
    Vector2D GetOr();

    friend class Interaccion;
};