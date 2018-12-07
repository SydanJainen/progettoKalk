#include "palettewidget.h"

paletteWidget::paletteWidget(QWidget *parent) : QWidget(parent)
{
    gridLayout = new QGridLayout(this);
    gestioneColore = new colorDisplay();
    wind = new displayPalette();

    //creo tasti
    add = new QPushButton(tr("+"));
    complementare = new QPushButton(tr("Complementare"));
    findAndReplace = new QPushButton(tr("trova e rimuovi"));
    desat = new QPushButton(tr("Desaturazione"));
    findM = new QPushButton(tr("trova >"));
    findm = new QPushButton(tr("trova <"));
    fill = new QPushButton(tr("fill"));
    inserisci = new QPushButton(tr("inserisci"));
    //addo tasti
    gridLayout->addWidget(wind,0,0,1,4);
    gridLayout->addWidget(add,1,0);
    gridLayout->addWidget(complementare,1,1);
    gridLayout->addWidget(findAndReplace,1,2);
    gridLayout->addWidget(desat,1,3);
    gridLayout->addWidget(fill , 2,0);
    gridLayout->addWidget(findM,2,1);
    gridLayout->addWidget(findm,2,2);
    gridLayout->addWidget(gestioneColore,0,4,2,2);
    gridLayout->addWidget(inserisci,2,4,1,2);

    creaConnect();

}

void paletteWidget::creaConnect(){
    connect(wind->primo->modifica,SIGNAL(clicked()),this,SLOT(setGestioneColore()));
    connect(wind->secondo->modifica,SIGNAL(clicked()),this,SLOT(setGestioneColore()));
    connect(wind->terzo->modifica,SIGNAL(clicked()),this,SLOT(setGestioneColore()));
    connect(wind->quarto->modifica,SIGNAL(clicked()),this,SLOT(setGestioneColore()));
    connect(wind->quinto->modifica,SIGNAL(clicked()),this,SLOT(setGestioneColore()));
    connect(inserisci,SIGNAL(clicked()),this,SLOT(setGestioneColore()));
    connect(gestioneColore->rSlider,SIGNAL(valueChanged(int)),this,SLOT(updateInserisciRed(int)));
    connect(gestioneColore->gSlider,SIGNAL(valueChanged(int)),this,SLOT(updateInserisciGreen(int)));
    connect(gestioneColore->bSlider,SIGNAL(valueChanged(int)),this,SLOT(updateInserisciBlue(int)));
    connect(complementare,SIGNAL(clicked()),this,SLOT(mainPaletteController()));
    connect(desat,SIGNAL(clicked()),this,SLOT(mainPaletteController()));
    connect(findM,SIGNAL(clicked()),this,SLOT(mainPaletteController()));
    connect(findm,SIGNAL(clicked()),this,SLOT(mainPaletteController()));
    connect(add,SIGNAL(clicked()),this,SLOT(mainPaletteController()));
    connect(fill,SIGNAL(clicked()),this,SLOT(mainPaletteController()));
    connect(findAndReplace,SIGNAL(clicked()),this,SLOT(mainPaletteController()));
}

void paletteWidget::mainPaletteController(){
    oggetto = new Palette();
    if(dynamic_cast<Palette*>(oggetto)){
        static_cast<Palette*>(oggetto)->inserisci(Color(wind->primo->modifica->property("red").toInt(),wind->primo->modifica->property("green").toInt(),(wind->primo->modifica->property("blue")).toInt()));
        static_cast<Palette*>(oggetto)->inserisci(Color(wind->secondo->modifica->property("red").toInt(),wind->secondo->modifica->property("green").toInt(),(wind->secondo->modifica->property("blue")).toInt()));
        static_cast<Palette*>(oggetto)->inserisci(Color(wind->terzo->modifica->property("red").toInt(),wind->terzo->modifica->property("green").toInt(),(wind->terzo->modifica->property("blue")).toInt()));
        static_cast<Palette*>(oggetto)->inserisci(Color(wind->quarto->modifica->property("red").toInt(),wind->quarto->modifica->property("green").toInt(),(wind->quarto->modifica->property("blue")).toInt()));
        static_cast<Palette*>(oggetto)->inserisci(Color(wind->quinto->modifica->property("red").toInt(),wind->quinto->modifica->property("green").toInt(),(wind->quinto->modifica->property("blue")).toInt()));
        QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
        QString pigiedValue = clickedButton->text();
        if(pigiedValue == QString("Complementare")){
            oggetto->complementare();
        }
        if(pigiedValue == QString("Desaturazione")){
            oggetto->desat();
        }
        if(pigiedValue == QString("trova >")){
            int index = static_cast<Palette*>(oggetto)->returnIndexMax();

            gestioneColore->setBlue(static_cast<Palette*>(oggetto)->getBlueFrom(index));
            gestioneColore->setRed(static_cast<Palette*>(oggetto)->getRedFrom(index));
            gestioneColore->setGreen(static_cast<Palette*>(oggetto)->getGreenFrom(index));
            inserisci->setProperty("nome",clickedButton->property("nome"));
            inserisci->setProperty("red",QVariant(static_cast<Palette*>(oggetto)->getRedFrom(index)));
            inserisci->setProperty("green",QVariant(static_cast<Palette*>(oggetto)->getGreenFrom(index)));
            inserisci->setProperty("blue",QVariant(static_cast<Palette*>(oggetto)->getBlueFrom(index)));
        }
        if(pigiedValue == QString("trova <")){
            int index = static_cast<Palette*>(oggetto)->returnIndexMin();
            gestioneColore->setBlue(static_cast<Palette*>(oggetto)->getBlueFrom(index));
            gestioneColore->setRed(static_cast<Palette*>(oggetto)->getRedFrom(index));
            gestioneColore->setGreen(static_cast<Palette*>(oggetto)->getGreenFrom(index));
            inserisci->setProperty("nome",clickedButton->property("nome"));
            inserisci->setProperty("red",QVariant(static_cast<Palette*>(oggetto)->getRedFrom(index)));
            inserisci->setProperty("green",QVariant(static_cast<Palette*>(oggetto)->getGreenFrom(index)));
            inserisci->setProperty("blue",QVariant(static_cast<Palette*>(oggetto)->getBlueFrom(index)));
        }
        if(pigiedValue == QString("+")){
            Color app((inserisci->property("red")).toInt(),(inserisci->property("green")).toInt(),(inserisci->property("blue")).toInt());
            oggetto->add(app);
        }
        if(pigiedValue == QString("fill")){
            Color app((inserisci->property("red")).toInt(),(inserisci->property("green")).toInt(),(inserisci->property("blue")).toInt());
            static_cast<Palette*>(oggetto)->fill(app);
        }
        if(pigiedValue == QString("trova e rimuovi")){
            Color app((inserisci->property("red")).toInt(),(inserisci->property("green")).toInt(),(inserisci->property("blue")).toInt());
            oggetto->findReplace(app,Color(0));
        }

        setPaletteView(oggetto);
        clickedButton=0;
    }
}



void paletteWidget::setPaletteView(ColorGroup *oggetto){
    if(dynamic_cast<Palette*>(oggetto)){
        wind->primo->setColor(static_cast<Palette*>(oggetto)->getRedFrom(0),static_cast<Palette*>(oggetto)->getGreenFrom(0),static_cast<Palette*>(oggetto)->getBlueFrom(0));
        wind->secondo->setColor(static_cast<Palette*>(oggetto)->getRedFrom(1),static_cast<Palette*>(oggetto)->getGreenFrom(1),static_cast<Palette*>(oggetto)->getBlueFrom(1));
        wind->terzo->setColor(static_cast<Palette*>(oggetto)->getRedFrom(2),static_cast<Palette*>(oggetto)->getGreenFrom(2),static_cast<Palette*>(oggetto)->getBlueFrom(2));
        wind->quarto->setColor(static_cast<Palette*>(oggetto)->getRedFrom(3),static_cast<Palette*>(oggetto)->getGreenFrom(3),static_cast<Palette*>(oggetto)->getBlueFrom(3));
        wind->quinto->setColor(static_cast<Palette*>(oggetto)->getRedFrom(4),static_cast<Palette*>(oggetto)->getGreenFrom(4),static_cast<Palette*>(oggetto)->getBlueFrom(4));

    }
}

void paletteWidget::setGestioneColore(){
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString pigiedValue = clickedButton->text();
    if(pigiedValue == QString("modifica") || pigiedValue == QString("inserisci")){
        gestioneColore->setBlue((clickedButton->property("blue")).toInt());
        gestioneColore->setRed((clickedButton->property("red")).toInt());
        gestioneColore->setGreen((clickedButton->property("green")).toInt());
        inserisci->setProperty("nome",clickedButton->property("nome"));
        inserisci->setProperty("red",clickedButton->property("red"));
        inserisci->setProperty("green",clickedButton->property("green"));
        inserisci->setProperty("blue",clickedButton->property("blue"));
    }
    if(pigiedValue == QString("rimuovi")){
        gestioneColore->setBlue(0);
        gestioneColore->setRed(0);
        gestioneColore->setGreen(0);
    }
    if(pigiedValue == QString("inserisci")){
        QString nome =inserisci->property("nome").toString();
        if(nome==QString("primo")){
            wind->primo->setColor((inserisci->property("red")).toInt(),(inserisci->property("green")).toInt(),(inserisci->property("blue")).toInt());
        }
        if(nome==QString("secondo")){
             wind->secondo->setColor((inserisci->property("red")).toInt(),(inserisci->property("green")).toInt(),(inserisci->property("blue")).toInt());
        }
        if(nome==QString("terzo")){
             wind->terzo->setColor((inserisci->property("red")).toInt(),(inserisci->property("green")).toInt(),(inserisci->property("blue")).toInt());
        }
        if(nome==QString("quarto")){
             wind->quarto->setColor((inserisci->property("red")).toInt(),(inserisci->property("green")).toInt(),(inserisci->property("blue")).toInt());
        }
        if(nome==QString("quinto")){
             wind->quinto->setColor((inserisci->property("red")).toInt(),(inserisci->property("green")).toInt(),(inserisci->property("blue")).toInt());
        }
    }
    clickedButton=0;
}

void paletteWidget::updateInserisciRed(int value){
    inserisci->setProperty("red",QVariant(value));
}

void paletteWidget::updateInserisciGreen(int value){
    inserisci->setProperty("green",QVariant(value));
}

void paletteWidget::updateInserisciBlue(int value){
    inserisci->setProperty("blue",QVariant(value));
}

paletteWidget::~paletteWidget(){
    delete add;
    delete complementare;
    delete findAndReplace;
    delete desat;
    delete fill;
    delete findM;
    delete findm;
    delete inserisci;
    delete wind;
    delete gestioneColore;
    delete gridLayout;
}

