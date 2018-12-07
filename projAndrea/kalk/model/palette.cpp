#include "model/palette.h"

Palette::Palette(){
    size = 0;
}

Palette::Palette(const int& dim){
    size=dim;
    for(int i=0; i<size; i++){
        colori.push_back(Color());
    }
}

Palette::Palette(const int& dim, const Color & costr){
    size=dim;
    for(int i=0; i<size; i++){
        colori.push_back(costr);
    }
}

Palette::Palette(const Palette& copia){
    if(this != &copia){
        size=copia.size;
        colori.clear();
        auto it = copia.colori.begin();
        for(int i=0; i<size; i++){
            colori.push_back(it[i]);
        }
    }
}

//Palette::~Palette(){}

void Palette::opacity(const int & valore){
    auto it = colori.begin();
    for (int i=0; i<size; i++){
        it[i].setOpacity(static_cast<unsigned int>(valore));
    }
}

void Palette::add(const Color& addendo){
    auto it = colori.begin();
    for (int i=0; i<size; i++){
        it[i]=it[i]+addendo;
    }
}

void Palette::complementare(){
    auto it = colori.begin();
    for (int i=0; i<size; i++){
        it[i]=it[i].Complementare();
    }
}

void Palette::findReplace(const Color& cerca, const Color& sostituisci){
    auto it = colori.begin();
    for (int i=0; i<size; i++){
        if(it[i]==cerca){
            it[i]=sostituisci;
        }
    }
}

void Palette::desat(){
    auto it = colori.begin();
    for (int i=0; i<size; i++){
        it[i]=it[i].Desaturazione();
    }
}

void Palette::rimuovi(const int& index){
    --size;
    auto it = colori.begin();
    colori.erase (it+index);
}

void Palette::inserisci(const Color& colore){
    ++size;
    colori.push_back(Color (colore));
}

void Palette::fill(const Color& sostituisci){
    auto it = colori.begin();
    for (int i=0; i<size; i++){
        it[i]=sostituisci;
    }
}

void Palette::sostituisci(const Color& sostituisci, const int& posizione){
    auto it = colori.begin();
    it[posizione]=sostituisci;

}

int Palette::returnIndexMax(){
    auto it = colori.begin();
    int maxlocale = 0;
    for (int i=1; i<size; i++){
        if(it[i]>it[maxlocale]){
            maxlocale=i;
        }
    }
    return maxlocale;
}

int Palette::returnIndexMin(){
    auto it = colori.begin();
    int minlocale = 0;
    for (int i=1; i<size; i++){
        if(it[i]<it[minlocale]){
            minlocale=i;
        }
    }
    return minlocale;
}

int Palette::getRedFrom(const int& index){
    return static_cast<int>((colori.at(index)).getRed());
}

int Palette::getBlueFrom(const int& index){
    return static_cast<int>((colori.at(index)).getBlue());
}

int Palette::getGreenFrom(const int& index){
    return static_cast<int>((colori.at(index)).getGreen());
}

int Palette::getOpacityFrom(const int& index){
    return static_cast<int>((colori.at(index)).getOpacity());
}

void Palette::setRedAt(const int& index, const int& valore){
    colori.at(index).setRed(static_cast<unsigned int>(valore));
}

void Palette::setBlueAt(const int& index, const int& valore){
    colori.at(index).setBlue(static_cast<unsigned int>(valore));
}

void Palette::setGreenAt(const int& index, const int& valore){
    colori.at(index).setGreen(static_cast<unsigned int>(valore));
}

void Palette::setOpacityAt(const int& index, const int& valore){
    colori.at(index).setOpacity(static_cast<unsigned int>(valore));
}

Palette::~Palette(){

}


//aggiungere funzioni riordinaDecr e riordinaCr
