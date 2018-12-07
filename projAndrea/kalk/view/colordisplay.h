#ifndef COLORDISPLAY_H
#define COLORDISPLAY_H

#include <QWidget>
#include <QLabel>
#include "model/color.h"
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>

class colorDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit colorDisplay(QWidget *parent = 0);
    void setMaxRange();
    void creaConnect();
    void setColor(int,int,int);
    int getBlue();
    int getRed();
    int getGreen();
    ~colorDisplay();
    void createToolTipPushButton();
    void setPalette(QPushButton& , int , int , int);
    void setRed(int);
    void setGreen(int);
    void setBlue(int);
    QSlider *rSlider , *gSlider , *bSlider;

signals:
    void valueChanged(int);

public slots:
    void updateColorRed(int);
    void updateColorGreen(int);
    void updateColorBlue(int);
    void unaryController();
    void updateView();
    void generateHEX();


private:
    QHBoxLayout *horizontalLayout;
    QGridLayout *sliderLayout ,*buttonLayout;
    QLabel *redLabel ,*labelColor, *greenLabel , *blueLabel , *hexLabel , *colorLabel;
    QSpinBox *redLine , *greenLine , *blueLine ,*wave;
    QColor *visualColor=0;
    QPalette palette ,pal;
    QLineEdit *hexLine;
    QPushButton *complementare , *wavelength , *Analogo ,*Triade , *Tetrade , *Desaturazione, *primoC , *secondoC , *terzoC, *quartoC , *quintoC;
    Color * colorDaGestire;
    QFrame *line;


};

#endif // COLORDISPLAY_H
