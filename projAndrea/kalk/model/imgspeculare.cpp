#include "model/imgspeculare.h"

imgSpeculare::imgSpeculare():pixelArt (){
    vert=oriz=1;
}

imgSpeculare::imgSpeculare(const pixelArt& a):pixelArt (a){
    if(a.isSimmetricoX() && a.isSimmetricoY()){
        oriz=vert=true;
    }
    else if(a.isSimmetricoX()){
        vert=true;
        oriz=false;
    }
    else if(a.isSimmetricoY()){
        oriz=true;
        vert=false;
    }
    else{
        throw noSpeculare();
    }
}

imgSpeculare::imgSpeculare(const imgSpeculare& a):pixelArt (a){
    if(a.isSimmetricoX() && a.isSimmetricoY()){
        oriz=vert=true;
    }
    else if(a.isSimmetricoX()){
        vert=true;
        oriz=false;
    }
    else if(a.isSimmetricoY()){
        oriz=true;
        vert=false;
    }
    else{
        throw noSpeculare();
    }
}

void imgSpeculare::flipX(){
    if(!(vert)){
        for(int i=0; i<getN()/2;i++){
            for (int j=0; j<getM(); j++){
                if(!(getElement(i,j)==getElement(getN()-1-i, j))){
                    pixelArt::addColore(getElement(i,j),getN()-1-i, j);

                }
            }
        }
        vert=true;
    }
}

void imgSpeculare::flipY(){
    if(!(oriz) ){
        for(int i=0; i<getN();i++){
            for (int j=0; j<getM()/2; j++){
                if(!(getElement(i,j)==getElement(i, getM()-j-1))){
                    pixelArt::addColore(getElement(i,j),i,getM()-j-1);

                }
            }
        }
        oriz=true;
    }
}

void imgSpeculare::addColore(const Color& a, const int& coord1, const int& coord2){
    pixelArt::addColore(a, coord1, coord2);
    if(oriz && vert){
        pixelArt::addColore(a, getN()-coord1-1, getM()-coord2-1);
    }
    if(oriz){
        pixelArt::addColore(a, coord1, getM()-coord2-1);
    }
    if(vert){
        pixelArt::addColore(a, getN()-coord1-1 , coord2);
    }
}
