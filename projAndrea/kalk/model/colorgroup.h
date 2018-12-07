#ifndef COLORGROUP_H
#define COLORGROUP_H
#include "color.h"

class ColorGroup{
private:

public:
    ColorGroup();
    virtual ~ColorGroup()=default; //definisco la classe astratta

    virtual void opacity(const int&)=0;//setter di opacity su tutto il gruppo
    virtual void add(const Color&)=0; //aggiunge un colore al gruppo
    virtual void complementare()=0; //fa il complementare dei valori del gruppo
    virtual void findReplace(const Color& , const Color&)=0; // cerca un colore in tutte le posizioni del gruppo e lo rimpiazza
    virtual void desat()=0; // applica desat per ogni elemento del gruppo
};

#endif // COLORGROUP_H
