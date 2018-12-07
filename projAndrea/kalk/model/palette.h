#ifndef PALETTE_H
#define PALETTE_H
#include"model/colorgroup.h"

class Palette:public ColorGroup{
public:
    Palette();//costruisce la palette vuota
    Palette(const int&);//costruisce la palette con n elementi bianchi
    Palette(const int&, const Color &);
    Palette(const Palette&);//costruttore di copia

    virtual ~Palette() throw(); //se in lab dà problemi togli default e togli il distruttore con {} dal commento nel .cpp

    //metodi che overridano quelli di colorgroup
    void opacity(const int&) override;//setter di opacity su tutti i colori della palette
    void add(const Color&) override; //somma un colore a tutti i colori della palette
    void complementare() override; //fa il complementare di tutti i colori della palette
    void findReplace(const Color& , const Color&) override; // cerca un colore in tutte le posizioni della palette e lo rimpiazza con il colore passato
    void desat() override; // applica desat per ogni colore della palette

    //metodi propri della classe palette
    void rimuovi(const int&);//rimuove l'elemento alla posizione n e diminuisce la size di 1
    void inserisci(const Color&);//aggiunge un nuovo colore alla fine della palette
    void fill(const Color&);//riempie la palette di un colore eliminando gli altri
    void sostituisci(const Color&, const int &);//sostituisce un colore al colore presente alla posizione passata
    int returnIndexMax() ;//mi ritorna l'indice del massimo dei figli sulla base della luminosità
    int returnIndexMin() ;//mi ritorna l'indice del minimo dei figli sulla base della luminosità

    //3 getter, 3 setter con indice e valore
    int getRedFrom(const int&);//mi restituisce il red di una posizione
    int getBlueFrom(const int&);//mi restituisce il blue di una posizione
    int getGreenFrom(const int&);//mi restituisce il green di una posizione
    int getOpacityFrom(const int&);//mi restituisce l'opacity di una posizione
    void setRedAt(const int&, const int&);//mi setta il red di una posizione
    void setBlueAt(const int&, const int&);//mi setta il blue di una posizione
    void setGreenAt(const int&, const int&);//mi setta il green di una posizione
    void setOpacityAt(const int&, const int&);//mi setta l'opacity di una posizione

private:
    int size;
    std::vector<Color> colori;
};

#endif // PALETTE_H
