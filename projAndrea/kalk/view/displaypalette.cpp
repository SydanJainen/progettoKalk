#include "displaypalette.h"

displayPalette::displayPalette(QWidget *parent) : QWidget(parent)
{
    group = new QGroupBox("La Mia Palette",this);
    horiLayout= new QHBoxLayout(group);
    primo = new colorCard();
    secondo = new colorCard();
    terzo = new colorCard();
    quarto = new colorCard();
    quinto = new colorCard();
    primo->modifica->setProperty("nome",QVariant("primo"));
    secondo->modifica->setProperty("nome",QVariant("secondo"));
    terzo->modifica->setProperty("nome",QVariant("terzo"));
    quarto->modifica->setProperty("nome",QVariant("quarto"));
    quinto->modifica->setProperty("nome",QVariant("quinto"));
    horiLayout->addWidget(primo);
    horiLayout->addWidget(secondo);
    horiLayout->addWidget(terzo);
    horiLayout->addWidget(quarto);
    horiLayout->addWidget(quinto);
}
displayPalette::~displayPalette(){
    delete quinto;
    delete quarto;
    delete terzo;
    delete secondo;
    delete primo;
    delete horiLayout;
    delete group;
}
