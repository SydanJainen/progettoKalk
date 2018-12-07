#ifndef COLOR_H
#define COLOR_H

#include <QObject>
#include <vector>
#include <iostream>
#include <cmath>

class divisioneZero{};

class Color{
private:
    unsigned int r,g,b,a;
    double fattore[3];
    static unsigned int hexconverter(const char&, const char&);
    static bool compare (const double &, const double &);

public:
    Color();//costruttore di default a r=255, g=255 , b=255, a=255;
    Color(const unsigned int&);//costruttore ad un parametro e setta r,g,b, a valore x ( x compreso tra 0 , 255)
    Color(const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int& opacity = 255);// costruttore con parametri
    Color(const Color& x);

    //metodi getter e/o setter
    void setOpacity(const unsigned int&);
    void setRed(const unsigned int&);
    void setGreen(const unsigned int&);
    void setBlue(const unsigned int&);
    void setFattore(const double&, const double&, const double&);
    unsigned int getOpacity() const;
    unsigned int getRed() const;
    unsigned int getGreen() const;
    unsigned int getBlue() const;

    //metodi di conversione da/a RGB a/da altre codifiche (HSV, HEX)
    std::vector<double> toHSV() const;  //HSV usa 3 coordinate con valori che sono da 0 a 360 per H e decimali compresi fra 0 e 1 per S e V contenuti in una vector di double
    static Color HSVtoRGB(const std::vector<double>& hsv);//converte una vector di double con 3 valori che rappresenta un colore HSV in un Color
    std::string toHEX() const;//converte il Color di invocazione in una stringa HEX
    static Color HEXtoRGB(const std::string&);//converte un HEX in Color

    //metodi di calcolo di valori sui colori, ma pure definiscono palette di colori
    Color Complementare() const;//return Color( 255-x.getRed() , 255-x.getGreen() , 255-x.getBlue() , 255-x.getOpacity())
    static Color wavelength(const int&);//metodo statico che data una lunghezza d'onda in nanometri mi ritorna un RGB
    std::vector<Color> Analogo (const unsigned int& gradi = 30) const;//conversione in hsv e traslazione di gradi%360 sulla H di HSV
    std::vector<Color> Triade () const ; //richiama Analogo a 120°
    std::vector<Color> Tetrade() const ; //richiama analogo a 90°
    Color Desaturazione() const; //ritorna un colore desaturato rispetto al fattore di desaturazione del colore (che puo' essere modificato, ma di default ha i valori 0.299, 0.587, 0.114

    Color& operator =(const Color& );

};

//overloading degli operatori esterni alla classe, mantenuti quelli delle operazioni aritmetiche se eventualmente si volesse ampliare il progetto con operazioni multiple una dopo l'altra
Color operator +(const Color& , const Color& );
Color operator -(const Color& , const Color& );
Color operator *(const Color& , const Color& );
Color operator *(const Color& , const unsigned int );
Color operator /(const Color& , const Color& );
Color operator /(const Color& , const unsigned int );
bool operator ==(const Color& ,const Color& );
bool operator !=(const Color& ,const Color& );
bool operator <(const Color& ,const Color& );
bool operator >(const Color&, const Color& );
#endif // COLOR_H
