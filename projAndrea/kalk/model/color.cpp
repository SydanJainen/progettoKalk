#include "color.h"
unsigned int Color::hexconverter(const char& x, const char& y){
    unsigned int a=0, b=0, i = 0;
    char index[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 'A', 'B', 'C', 'D', 'E','F'};
    bool bo = true;
    while(bo){
        if(x==index[i]){
            a=i;
            bo=false;
            i=0;
        }else{
            i++;
        }
    }

    bo = true;

    while(bo){
        if(y==index[i]){
            b=i;
            bo=false;
        }else{
            i++;
        }
    }

    return (a*(16))+(b);
}

bool Color::compare(const double & primo, const double & secondo){
    double epsilonpos = 0.000001;
    double epsilonneg = -epsilonpos;
    double result = primo - secondo;
    if(result>epsilonneg && result<epsilonpos){
        return true;
    }
    else if(result<0 && result>epsilonneg){
        return true;
    }
    return false;

}

Color::Color(){
    r=255;
    g=255;
    b=255;
    a=255;
    fattore[0] = 0.299;
    fattore[1] = 0.587;
    fattore[2] = 0.114;
}

Color::Color(const unsigned int& x){
    r=g=b=x;
    a=255;
    fattore[0] = 0.299;
    fattore[1] = 0.587;
    fattore[2] = 0.114;
}

Color::Color(const unsigned int& red, const unsigned int& green, const unsigned int& blue, const unsigned int& opacity){
    r=red;
    g=green;
    b=blue;
    a=opacity;
    fattore[0] = 0.299;
    fattore[1] = 0.587;
    fattore[2] = 0.114;
}

Color::Color(const Color& x){
    fattore[0] = x.fattore[0];
    fattore[1] = x.fattore[1];
    fattore[2] = x.fattore[2];
    r=x.r;
    g=x.g;
    b=x.b;
    a=x.a;
}


void Color::setOpacity(const unsigned int& opacity){
    a=opacity;
}

void Color::setRed(const unsigned int& red){
    r=red;
}

void Color::setGreen(const unsigned int& green){
    g=green;
}

void Color::setBlue(const unsigned int& blue){
    b=blue;
}

unsigned int Color::getOpacity() const{
    return a;
}

unsigned int Color::getRed() const{
    return r;
}

unsigned int  Color::getGreen() const{
    return g;
}

unsigned int  Color::getBlue() const{
    return b;
}

Color  Color::Complementare() const{
    std::vector<double> HSV = this->toHSV();
    double primo = HSV.at(0);
    primo+=180.0;
    HSV.at(0) = primo;
    HSV.at(0) = fmod(HSV.at(0),  360);
    Color ritorno( HSVtoRGB(HSV));
    return ritorno;

    /*Color ritorno( 255-r , 255-g , 255-b , 255-a);
    return ritorno;*/
}

Color  Color::wavelength(const int& londa){//conversione di una lunghezza d'onda in nanometri a un rgb. METODO STATICO

    double attenuation;
    double gamma = 0.8;
    double R, G, B;

    if (londa >= 380 && londa < 440) {
    attenuation = 0.3 + 0.7 * (londa - 380) / (440 - 380);
    R = pow(((-static_cast<double>(londa - 440) / static_cast<double>(440 - 380)) * attenuation) , gamma);
    G = 0.0;
    B = pow((1.0 * attenuation) , gamma);
    }
    else if (londa >= 440 && londa < 490) {
    R = 0.0;
    G = pow((static_cast<double>(londa - 440) / static_cast<double>(490 - 440)) , gamma);
    B = 1.0;
    }
    else if (londa >= 490 && londa < 510) {
    R = 0.0;
    G = 1.0;
    B = pow((-static_cast<double>(londa - 510) / static_cast<double>(510 - 490)) , gamma);
    }
    else if (londa >= 510 && londa < 580) {
    R = pow((static_cast<double>(londa - 510) / static_cast<double>(580 - 510)) , gamma);
    G = 1.0;
    B = 0.0;
    }
    else if (londa >= 580 && londa < 645) {
    R = 1.0;
    G = pow((-static_cast<double>(londa - 645) / static_cast<double>(645 - 580)) , gamma);
    B = 0.0;
    }
    else if (londa >= 645 && londa < 750) {
    attenuation = 0.3 + 0.7 * static_cast<double>(750 - londa) / static_cast<double>(750 - 645);
    R = pow((1.0 * attenuation) , gamma);
    G = 0.0;
    B = 0.0;
    }
    else {
    R = 0.0;
    G = 0.0;
    B = 0.0;
    }
    R = R * 255;
    G = G * 255;
    B = B * 255;
    Color ritorno(static_cast<unsigned int> (R), static_cast<unsigned int> (G), static_cast<unsigned int> (B), 255);
    return ritorno;//facendo static_cast mi arrotonda alla cifra intera piu' bassa (perde la parte decimale) che e' cio' che voglio
}


std::vector<double> Color::toHSV() const{
    std::vector<double> ritorno; //vector di double di appoggio in cui inserisco i valori VSH dalla testa (cosi' in ordine conterra' HSV). Poi lo ritorno;
    std::vector<double>::iterator it = ritorno.begin();
    double H = 0;
    double S = 0;
    double V = 0;
    double maxRGB;
    double minRGB;
    double delta;
    double erre = static_cast<double>(r)/255;
    double gi = static_cast<double>(g)/255;
    double bi = static_cast<double>(b)/255;

    minRGB = static_cast<double>(std::min(erre,std::min(gi,bi)));

    maxRGB = static_cast<double>(std::max(erre,std::max(gi,bi)));

    delta = maxRGB-minRGB;

    if(compare(delta, 0)){
        H=0.0;
    }
    else{
        if(compare(maxRGB, erre)){
           H = 60* (fmod(((gi-bi)/delta), 6));
        }
        else if(compare (maxRGB, gi)){
            H = 60* (((bi-erre)/delta)+ 2.0);
        }
        else if(compare (maxRGB, bi)){
            H = 60* (((erre-gi)/delta)+ 4.0);
        }
    }

    if(compare(maxRGB, 0)){
        S = 0;
    }
    else{
        S = (delta)/maxRGB;
    }

    V = maxRGB;

    it = ritorno.insert(it, V);
    it = ritorno.insert(it, S);
    it = ritorno.insert(it, H);
    return ritorno;
}

std::string Color::toHEX() const{// prende in input un oggetto di tipo Color e ritorna una string contenente i tre valori HEX corrispondenti ai 3 valori di RGB
    std::string index[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E","F"};
    int unor = (r/16)%16;
    int duer = r%16;
    int unog = (g/16)%16;
    int dueg = g%16;
    int unob = (b/16)%16;
    int dueb = b%16;
    std::string HEX = ""+index[unor]+index[duer]+index[unog]+index[dueg]+index[unob]+index[dueb];
    return HEX;
}

Color Color::HEXtoRGB(const std::string& hex){
    Color ritorno((hexconverter(hex[1], hex[2])), (hexconverter(hex[3], hex[4])), (hexconverter(hex[5], hex[6])),255);
    return ritorno;
}

std::vector<Color> Color::Analogo(const unsigned int& gradi) const{ //devo ritornare una vector di color con numero colori compreso fra 2 e 5
    std::vector<double> hsv = this->toHSV(); //converto il colore di invocazione in hsv
    std::vector<double> hsv1 = hsv; //creo una vector di appoggio che modifico in relazione di hsv
    double gr = fmod(gradi,360); //controllo per evitare che i gradi non siano normalizzati
    std::vector<Color> coloriAnaloghi;//la vector che ritorno alla fine
    coloriAnaloghi.push_back(*this);//push_back() inserisce una copia di *this
    std::vector<double>::iterator it = hsv.begin();
    std::vector<double>::iterator it1 = hsv1.begin();
    //ho la creazione di 5 colori HSV con 5 H diverse (H, H+gr, H-gr, H+2gr, H-2gr)
    if(it[0]+gr > 360){
        it1[0]=(hsv)[0]+gr-360;
        coloriAnaloghi.push_back((HSVtoRGB(hsv1)));
    }
    else if(it[0]+gr < 0){
        it1[0]=(hsv)[0]+gr+360;
        coloriAnaloghi.push_back((HSVtoRGB(hsv1)));
    }

    else{
        it1[0]=it[0]+gr;
        coloriAnaloghi.push_back((HSVtoRGB(hsv1)));
    }

    if(it[0]-gr > 360){
        it1[0]=it[0]-gr-360;
        coloriAnaloghi.push_back((HSVtoRGB(hsv1)));
    }

    else if(it[0]-gr < 0){
        it1[0]=it[0]-gr+360;
        coloriAnaloghi.push_back((HSVtoRGB(hsv1)));
    }

    else{
        it1[0]=it[0]-gr;
        coloriAnaloghi.push_back((HSVtoRGB(hsv1)));
    }
    if(it[0]+2*gr > 360){
        it1[0]=it[0]+2*gr-360;
        coloriAnaloghi.push_back((HSVtoRGB(hsv1)));
    }

    else if(it[0]+2*gr < 0){
        it1[0]=it[0]+2*gr+360;
        coloriAnaloghi.push_back((HSVtoRGB(hsv1)));
    }

    else{
        it1[0]=it[0]+2*gr;
        coloriAnaloghi.push_back((HSVtoRGB(hsv1)));
    }

    if(it[0]-2*gr > 360){
        it1[0]=it[0]-2*gr-360;
        coloriAnaloghi.push_back((HSVtoRGB(hsv1)));
    }

    else if(it[0]-2*gr < 0){
        it1[0]=it[0]-2*gr+360;
        coloriAnaloghi.push_back((HSVtoRGB(hsv1)));
    }

    else{
        it1[0]=it[0]-2*gr;
        coloriAnaloghi.push_back((HSVtoRGB(hsv1)));
    }

    return coloriAnaloghi;
}

std::vector<Color> Color::Triade () const {
    //ritorna una vector di elementi formati dagli elementi in posizione v[1],v[2],v[3]
    std::vector<Color> coloriTriade;
    coloriTriade = this->Analogo(120);
    coloriTriade.pop_back();
    coloriTriade.pop_back();
    return coloriTriade;
}

std::vector<Color> Color::Tetrade () const {
    //ritorna una vector di elementi formati dagli elementi in posizione v[1],v[2],v[3],v[4]
    std::vector<Color> coloriTetrade;
    coloriTetrade = this->Analogo(90);
    coloriTetrade.pop_back();
    return coloriTetrade;
}

Color Color::HSVtoRGB(const std::vector<double>& hsv){
    double H = hsv[0];
    double S = hsv[1];
    double V = hsv[2];
    double C = V*S;
    double div = 60.0;
    double positive;
    if((fmod((H / div), 2) - 1)>0){
        positive = (fmod((H / div), 2) - 1);
    }
    else{
        positive = -(fmod((H / div), 2) - 1);
    }
    double X = C * (1 - positive);
    double M = V-C;
    double var_r = 0, var_g = 0, var_b = 0;

    if(0<=H && H<60){
        var_r = C;
        var_g = X;
        var_b = 0;
    }
    else if(60<=H && H<120){
        var_r = X;
        var_g = C;
        var_b = 0;
    }
    else if(120<=H && H<180){
        var_r = 0;
        var_g = C;
        var_b = X;
    }
    else if(180<=H && H<240){
        var_r = 0;
        var_g = X;
        var_b = C;
    }
    else if(240<=H && H<300){
        var_r = X;
        var_g = 0;
        var_b = C;
    }
    else if(300<=H && H<360){
        var_r = C;
        var_g = 0;
        var_b = X;
    }

       Color ritorno(static_cast<unsigned int>((var_r+M) * 255),static_cast<unsigned int>((var_g+M) * 255), static_cast<unsigned int>((var_b+M) * 255), 255);
       return  ritorno;//controllo sui valori di ingresso . nel caso finita
}

Color Color::Desaturazione() const{
    Color ritorno(static_cast<unsigned int>(r*fattore[0]),static_cast<unsigned int>(g*fattore[1]),static_cast<unsigned int>(b*fattore[2]),255);
    return ritorno;//ok
}

void Color::setFattore(const double& a, const double& b , const double& c){
    if(!((a+b+c)>1 || a>1  || b>1 || c>1 ||a <0 ||b<0||c<0)){
        fattore[0]=a;
        fattore[1]=b;
        fattore[2]=c;
    }
}

Color& Color::operator =(const Color& x){
    if(this!=&x){
        r=x.getRed();
        g=x.getGreen();
        b=x.getBlue();
        a=x.getOpacity();
    }
    return *this;
}

bool operator <(const Color& x , const Color& y){
    bool confronto =false;
    std::vector<double> hsv1 = x.toHSV();
    std::vector<double> hsv2 = y.toHSV();
    std::vector<double>::iterator it = hsv1.begin();
    std::vector<double>::iterator it1 = hsv2.begin();
    (it[2]<it1[2]) ? confronto=true : confronto=false;
    return confronto;
}

bool operator >(const Color& x , const Color& y){
    bool confronto =false;
    std::vector<double> hsv1 = x.toHSV();
    std::vector<double> hsv2 = y.toHSV();
    std::vector<double>::iterator it = hsv1.begin();
    std::vector<double>::iterator it1 = hsv2.begin();
    (it[2]>it1[2]) ? confronto=true : confronto=false;
    return confronto;
}


Color operator +(const Color& x, const Color& y){
    unsigned int red, green, blue;
    if((x.getRed()+y.getRed())>255){
        red=255;
    }
    else{
        red=x.getRed()+y.getRed();
    }

    if((x.getBlue()+y.getBlue())>255){
        blue=255;
    }
    else{
        blue=x.getBlue()+y.getBlue();
    }

    if((x.getGreen()+y.getGreen())>255){
        green=255;
    }
    else{
        green=x.getGreen()+y.getGreen();
    }

    Color ritorno(red, green, blue, 255);
    return ritorno;
}

Color operator -(const Color& x, const Color& y){
    unsigned int red, green, blue;
    if(y.getRed()>x.getRed()){
        red=0;
    }
    else{
        red=x.getRed()-y.getRed();
    }

    if(y.getBlue()>x.getBlue()){
        blue=0;
    }
    else{
        blue=x.getBlue()-y.getBlue();
    }

    if(y.getGreen()>x.getGreen()){
        green=0;
    }
    else{
        green=x.getGreen()-y.getGreen();
    }

    Color ritorno(red, green, blue, 255);
    return ritorno;
}

Color operator *(const Color& x, const unsigned int y){
    unsigned int red, green, blue;
    if((x.getRed()*y)>255){
        red=255;
    }
    else{
        red=x.getRed()*y;
    }

    if((x.getBlue()*y)>255){
        blue=255;
    }
    else{
        blue=x.getBlue()*y;
    }

    if((x.getGreen()*y)>255){
        green=255;
    }
    else{
        green=x.getGreen()*y;
    }

    Color ritorno(red, green, blue, 255);
    return ritorno;
}

Color operator *(const Color& x, const Color& y){
    unsigned int red, green, blue;
    if((x.getRed()*y.getRed())>255){
        red=255;
    }
    else{
        red=x.getRed()*y.getRed();
    }

    if((x.getBlue()*y.getBlue())>255){
        blue=255;
    }
    else{
        blue=x.getBlue()*y.getBlue();
    }

    if((x.getGreen()*y.getGreen())>255){
        green=255;
    }
    else{
        green=x.getGreen()*y.getGreen();
    }

    Color ritorno(red, green, blue, 255);
    return ritorno;
}

Color operator /(const Color& x, const Color& y){
    unsigned int red, green, blue;
    if((y.getRed()==0)||(y.getGreen()==0)||(y.getBlue()==0)||(y.getOpacity()==0)){
        throw divisioneZero();
    }
    else{
        red=x.getRed()/y.getRed();
        blue=x.getBlue()/y.getBlue();
        green=x.getGreen()/y.getGreen();
        Color ritorno(red, green, blue, 255);
        return ritorno;
    }
}

Color operator /(const Color& x, const unsigned int y){
    unsigned int red, green, blue;
    if(y==0){
        throw divisioneZero();
    }
    else{
        red=x.getRed()/y;
        blue=x.getBlue()/y;
        green=x.getGreen()/y;
        Color ritorno(red, green, blue, 255);
        return ritorno;
    }
}

bool operator == (const Color& x , const Color& y){
    if((x.getBlue()==y.getBlue()) && (x.getGreen()==y.getGreen()) && (x.getRed() == y.getRed()) && x.getOpacity() == y.getOpacity()){
        return true;
    }
    return false;
}

bool operator != (const Color& x , const Color& y){
    if((x.getBlue()==y.getBlue()) && (x.getGreen()==y.getGreen()) && (x.getRed() == y.getRed()) && x.getOpacity() == y.getOpacity()){
        return false;
    }
    return true;
}
