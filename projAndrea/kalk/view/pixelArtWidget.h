#ifndef PIXELARTWIDGET_H
#define PIXELARTWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <qgridlayout.h>
#include <QLabel>
#include <QCheckBox>
#include "view/colordisplay.h"
#include <model/colorgroup.h>
#include <model/pixelart.h>
#include <model/imgspeculare.h>


class pixelArtWidget : public QWidget
{
    Q_OBJECT
public:
    explicit pixelArtWidget(QWidget *parent = 0);
    void createMatrix(int,int);
    void insertColor(int x , int y , Color a);
    ~pixelArtWidget();
    void creaConnect();
    void setMatrixLayout(ColorGroup* oggetto);
    void abilitaSpec();
    void disabilitaSpec();
    void minColumnW(int);
    QColor getColore(int, int);

signals:

public slots:
    void mainControllerPixelArt();
    void clickedController(QTableWidgetItem*);
    void updateInserisciRed(int value);
    void updateInserisciGreen(int value);
    void updateInserisciBlue(int value);

private:
    QPushButton *flipX,*flipY,*spec, *create8 , *findReplace  , *add, *desat, *comp ,*scambiaH , *scambiaV , *inserisci;
    QTableWidget *matrice;
    QGridLayout *pixelArtLayout;
    colorDisplay *colore;
    QLabel *riga, *colonna;
    QLineEdit *rigaLine , *colonnaLine;
    ColorGroup *oggetto;




};

#endif // PIXELARTWIDGET_H
