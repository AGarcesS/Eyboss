
#pragma once
#include "Vector2D.h"
#include "Disparo.h"

class DisparoGancho : public Disparo {
private:
    bool feuer; //marca de disparo
    Vector2D posorigen; //origen del disparo
    bool orientacion; //orientación del disparo
    bool pared; //detecta la colisión con una plataforma
public:
    DisparoGancho() {
        radio = 1;
        longitud = 15.0;
        velocidad.x = 0;
        velocidad.y = 0;
        posorigen.x = posicion.x = 0;
        posorigen.y = posicion.y = 0;
        orientacion = true;
        pared = false;
        textura = "bin/texturas/gancho.png";
    }
    virtual ~DisparoGancho() {}    
    
    bool GetF();
    bool GetPared() { return pared; };
    bool GetOrientacion() { return orientacion; };
    Vector2D GetOr();
    
    void SetPared(bool f) { pared = f; };
    void SetOrientacion(bool f) { orientacion = f; };
    void SetPosOr(float ix, float iy);
    bool Limite();
    void SetF(bool f);    

    void Dibuja();
    void Mueve(float t);

    friend class Interaccion;
};