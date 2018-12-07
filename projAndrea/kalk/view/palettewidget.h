#ifndef PALETTEWIDGET_H
#define PALETTEWIDGET_H

#include <QWidget>
#include <QLabel>
#include "view/colordisplay.h"
#include "view/displaypalette.h"
#include <model/colorgroup.h>
#include <model/color.h>
#include <model/palette.h>

class paletteWidget : public QWidget
{
    Q_OBJECT
public:
    explicit paletteWidget(QWidget *parent = 0);
    void creaConnect();
    ~paletteWidget();
    void setPaletteView(ColorGroup *oggetto);

signals:


public slots:
    void setGestioneColore();
    void updateInserisciRed(int value);
    void updateInserisciGreen(int value);
    void updateInserisciBlue(int value);
    void mainPaletteController();



private:
    QPushButton *add,*complementare,*findAndReplace , *desat  , *findM ,*findm , *fill ,*inserisci;
    QGridLayout *gridLayout;
    colorDisplay *gestioneColore;
    displayPalette *wind;
    ColorGroup *oggetto;


};

#endif // PALETTEWIDGET_H
