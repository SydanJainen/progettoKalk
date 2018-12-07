#include "colorcard.h"

colorCard::colorCard(QWidget *parent) : QWidget(parent)
{
    verticalLayout = new QVBoxLayout(this);
    colorLabel = new QLabel();
    modifica = new QPushButton(tr("modifica"));
    rimuovi = new QPushButton(tr("rimuovi"));
    verticalLayout->addWidget(colorLabel);
    verticalLayout->addWidget(modifica);
    verticalLayout->addWidget(rimuovi);
    setColor(0,0,0);
    connect(rimuovi,SIGNAL(clicked()),this,SLOT(setBianco()));
    connect(modifica,SIGNAL(clicked()),this,SLOT(setText()));
}

void colorCard::setBianco(){
    setColor(255,255,255);
    modifica->setText(tr("inserisci"));
}

void colorCard::setText(){
    modifica->setText(tr("modifica"));
}

void colorCard::setColor(int r, int g, int b){
    if(visualColor!= nullptr) delete visualColor;
    visualColor = new QColor(r,g,b);
    palette = colorLabel->palette();
    palette.setColor(colorLabel->backgroundRole(), *visualColor);
    palette.setColor(colorLabel->foregroundRole(),*visualColor);
    colorLabel->setPalette(palette);
    colorLabel->setAutoFillBackground(true);
    setProp(r,g,b);

}

void colorCard::setProp(int r,int g, int b){
    modifica->setProperty("red",QVariant(r));
    modifica->setProperty("green",QVariant(g));
    modifica->setProperty("blue",QVariant(b));
}

colorCard::~colorCard(){
    delete visualColor;
    delete rimuovi;
    delete modifica;
    delete colorLabel;
    delete verticalLayout;
}

