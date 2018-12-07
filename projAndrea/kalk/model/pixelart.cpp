#include "model/pixelart.h"

pixelArt::pixelArt(){
    rig=0;
    col=0;
    griglia = nullptr;
}

pixelArt::pixelArt(const int& a){
    rig=a;
    col=a;
    griglia = new Color *[static_cast<unsigned int>(rig)];
    for(int i=0;i<rig;i++){
        griglia[i] = new Color[static_cast<unsigned int>(col)];
        for(int j=0;j<col;j++){
            griglia[i][j]=255;//uso il costruttore a 1 parametro di Color(unsigned int &) per far conversione a Color da unsigned int
        }
    }
}

pixelArt::pixelArt(const int& a, const Color& f){
    rig=a;
    col=a;
    griglia =new Color*[static_cast<unsigned int>(rig)];
    for(int i=0;i<rig;i++){
        griglia[i] = new Color[static_cast<unsigned int>(col)];
        for(int j=0;j<col;j++){
            griglia[i][j]=f;
        }
    }
}

pixelArt::pixelArt(const int& a, const int& b){
    rig=a;
    col=b;
    griglia = new Color*[static_cast<unsigned int>(rig)];
    for(int i=0;i<rig;i++){
        griglia[i] = new Color[static_cast<unsigned int>(col)];
        for(int j=0;j<col;j++){
            griglia[i][j]=255;
        }
    }
}

pixelArt::pixelArt(const int& a, const int& b, const Color& f){
    rig=a;
    col=b;
    griglia = new Color*[static_cast<unsigned int>(rig)];
    for(int i=0;i<rig;i++){
        griglia[i] = new Color[static_cast<unsigned int>(col)];
        for(int j=0;j<col;j++){
            griglia[i][j]=f;
        }
    }
}

pixelArt::pixelArt(const pixelArt& f){
    rig=f.rig;
    col=f.col;
    griglia = new Color*[static_cast<unsigned int>(rig)];
    for (int i=0; i<rig; i++){
        griglia[i] = new Color[static_cast<unsigned int>(col)];
        for (int j=0; j<col; j++){
            griglia[i][j]=f.griglia[i][j];
        }
    }
}

pixelArt::~pixelArt(){
    for (int i=0; i<rig; ++i){
        delete[] griglia[i];
    }
    delete[] griglia;
}

void pixelArt::addColore(const Color& f, const int& a, const int& b){
    griglia[a][b]=f;//assegnazione tramite costruttore a un parametro di Color
}

void pixelArt::scambiaOrizz() {//scambia sinistra e destra della griglia
    Color appoggio;
    for(int i=0;i<rig;i++){
          for(int j=0; j < static_cast<int>(col/2);j++){
              appoggio = griglia[i][j];
              griglia[i][j]=griglia[i][col-j-1];
              griglia[i][col-j-1]=appoggio;
          }
     }
}

void pixelArt::scambiaVert() {//scambia la parte superiore con quella inferiore della griglia
    Color appoggio;
    for(int j=0;j<rig;j++){
        for(int i=0;i < static_cast<int>(rig/2);i++){
            appoggio = griglia[i][j];
            griglia[i][j]=griglia[rig-i-1][j];
            griglia[rig-i-1][j]=appoggio;
        }
    }
}

bool pixelArt::isSimmetricoY() const{
    for(int i=0;i<rig;i++){
        for(int j=0;j<col/2;j++){
            if( griglia[i][j] != griglia[i][rig-j-1]){
                return false;
            }
        }
    }
    return true;
}

bool pixelArt::isSimmetricoX() const{
    for(int i=0;i<rig/2;i++){
        for(int j=0;j<col;j++){
           if(griglia[i][j]!= griglia[rig-i-1][j]){
                return false;
           }
        }
    }
    return true;
}

int pixelArt::getN() const{
    return rig;
}

int pixelArt::getM() const{
    return col;
}

Color& pixelArt::getElement(const int& i, const int& j){
    return griglia[i][j];
}

void pixelArt::opacity(const int& a){
    for ( int i=0;i<rig;i++){
        for(int j=0;j<col;j++){
            griglia[i][j].setOpacity(static_cast<unsigned int>(a));
        }
    }
}

void pixelArt::complementare(){
    for ( int i=0;i<rig;i++){
        for(int j=0;j<col;j++){
            griglia[i][j]=griglia[i][j].Complementare();
        }
    }
}

void pixelArt::desat(){
    for (int i=0;i<rig;i++){
        for(int j=0;j<col;j++){
            griglia[i][j]=griglia[i][j].Desaturazione();
        }
    }
}

void pixelArt::add(const Color& a){
     for (int i=0;i<rig;i++){
         for(int j=0;j<col;j++){
             griglia[i][j]=griglia[i][j]+a;//mia idea (ovvero faccio la add di un colore su ciascun Color del contenitore
         }
     }
}

void pixelArt::findReplace(const Color& a, const Color& b){
    for (int i=0;i<rig;i++){
        for(int j=0;j<col;j++){
            if(griglia[i][j]==a){
                griglia[i][j]=b;
            }
        }
    }
}

pixelArt& pixelArt::operator =(const pixelArt& c){
    if(this!= &c){
        for (int i=0; i<rig; ++i){
            delete[] griglia[i];
        }
        rig=c.rig;
        col=c.col;
        griglia = new Color *[static_cast<unsigned int>(rig)];
        for(int i=0; i<rig; i++){
            for(int j=0; j<col; j++){
                griglia[i][j]=c.griglia[i][j];
            }
        }
    }
    return *this;
}
