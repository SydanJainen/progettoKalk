#ifndef PIXELART_H
#define PIXELART_H
//#include <iterator>
#include"model/colorgroup.h"

class pixelArt:public ColorGroup{
public:
    //costruttori
    pixelArt();//griglia vuota
    pixelArt(const pixelArt &);//costruttore di copia
    pixelArt(const int&);//costruttore che crea una n*n con colore 255
    pixelArt(const int&, const Color&);//n*n con colore passato
    pixelArt(const int&, const int&) ;//costruttore che crea n*m con colore 255
    pixelArt(const int&, const int&, const Color&);//costruttore n*m con colore passato
    ~pixelArt() override;

    //metodi della classe
    virtual void addColore(const Color&, const int&, const int&);//FA SIDE EFFECT sostituisce in griglia alle coordinate i, j il colore passato
    void scambiaVert();//scambia la metà superiore della griglia con la metà inferiore specularmente rispetto al centro
    void scambiaOrizz();//scambia la metà sinistra della griglia con la metà destra specularmente rispetto al centro
    bool isSimmetricoX() const;//mi restituisce true se la griglia e' simmetrica verticalmente (meta' superiore simmetrica rispetto all'asse delle X)
    bool isSimmetricoY() const;//mi restituisce true se la griglia e' simmetrica orizzontalmente (meta' superiore simmetrica rispetto all'asse delle Y)

    //getter
    Color& getElement(const int&, const int&);
    int getN() const;
    int getM() const;

    //override
    void opacity(const int&) override;//setter di opacity su tutto il contenitore
    void add(const Color&) override; //aggiunge per ogni singolo colore svolge la somma su tutta la griglia
    void complementare() override; //fa il complementare dei valori del contenitore
    void findReplace(const Color&, const Color&) override; // cerca un colore in tutte le posizioni del contenitore e lo rimpiazza
    void desat() override; // applica desat per ogni elemento del contenitore

    pixelArt& operator =(const pixelArt& );
private:
    Color** griglia;//array bidimensionale
    int rig, col; // rig e col sono misure di altezza e larghezza della griglia del contenitore
};

#endif // PIXELART_H
