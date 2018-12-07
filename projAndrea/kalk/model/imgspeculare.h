#ifndef IMGSPECULARE_H
#define IMGSPECULARE_H
#include"model/pixelart.h"

class noSpeculare{};

class imgSpeculare:public pixelArt{
public:
    imgSpeculare();
    imgSpeculare(const pixelArt&);//costruttore a cui passo una pixelart
    imgSpeculare(const imgSpeculare&);//costruttore di copia
    void flipY();//rende la metà destra della griglia uguale a quella sinistra
    void flipX();//rende la metà destra della griglia uguale a quella sinistra
    void addColore(const Color&, const int&, const int &) override;
private:
    bool vert;//significa che la metà sinistra è uguale alla destra
    bool oriz;//significa che la metà inferiore è uguale alla superiore
};

#endif // IMGSPECULARE_H
