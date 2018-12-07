#include "qdisplaycolor.h"

QDisplayColor::QDisplayColor(QWidget *parent) : QMainWindow(parent)
{
    horizontalLayout = new QHBoxLayout(this);
    sliderLayout = new QGridLayout();
    sliderLayout->setVerticalSpacing(20);

    //SETTING DELLO SLIDER LAYOUT
    rSlider = new QSlider();
    rSlider->setOrientation(Qt::Horizontal);
    gSlider = new QSlider();
    gSlider->setOrientation(Qt::Horizontal);
    bSlider = new QSlider();
    bSlider->setOrientation(Qt::Horizontal);

    //setto upperbound -lowerbound
    setMaxSlider();
    setMinSlider();

    redLabel = new QLabel(tr("red"));
    greenLabel = new QLabel(tr("green"));
    blueLabel = new QLabel(tr("blue"));
    hexLabel = new QLabel(tr("hex"));
    hLabel = new QLabel(tr("HSV"));


    //QLineEdit
    redLine = new QLineEdit();
    greenLine =new QLineEdit();
    blueLine = new QLineEdit();
    hexLine = new QLineEdit();
    hLine = new QLineEdit();
    sLine = new QLineEdit();
    vLine = new QLineEdit();

    sliderLayout->addWidget(redLabel,0,0);
    sliderLayout->addWidget(greenLabel,1,0);
    sliderLayout->addWidget(blueLabel ,2,0);
    sliderLayout->addWidget(rSlider,0,2);
    sliderLayout->addWidget(gSlider ,1,2);
    sliderLayout->addWidget(bSlider,2,2);
    sliderLayout->addWidget(redLine,0,1);
    sliderLayout->addWidget(greenLine,1,1);
    sliderLayout->addWidget(blueLine,2,1);
    sliderLayout->addWidget(hexLabel ,3,0);
    sliderLayout->addWidget(hexLine ,3 ,1);
    sliderLayout->addWidget(hLabel ,4,0);
    sliderLayout->addWidget(hLine , 4,1);
    sliderLayout->addWidget(sLine , 4,2);
    sliderLayout->addWidget(vLine ,4,3);
}

void QDisplayColor::setMaxSlider(){
    rSlider->setMaximum(255);
    gSlider->setMaximum(255);
    bSlider->setMaximum(255);
}

void QDisplayColor::setMinSlider(){
    rSlider->setMinimum(0);
    gSlider->setMinimum(0);
    bSlider->setMinimum(0);
}
