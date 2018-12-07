#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow){
    ui->setupUi(this);
    setFixedSize(1300,800);


    //inizializzo TabWidget
    tabContainer=new QTabWidget(this);
    tabContainer->setGeometry(QRect(QPoint(0,20),QSize(1300,780)));
    tabContainer->setFont(QFont("Calibri",16));

    //creo le singole tab
    coloriTab = new QWidget();
    coloriTab->setFont(QFont("Calibri",16));

    paletteTab = new QWidget();
    paletteTab->setFont(QFont("Calibri",16));

    pixelartTab = new QWidget();
    pixelartTab->setFont(QFont("Calibri",16));

    //popolo le singole tab
    setColori();
    setPaletteTab();
    setPixelArtTab();
    //addo le tab

    tabContainer->addTab(coloriTab,tr("Colori"));
    tabContainer->addTab(paletteTab,tr("Palette"));
    tabContainer->addTab(pixelartTab,tr("PixelArt"));

    //creo la connessione tra una funzione l'evento pigia il bottone
    //connect(quit,SIGNAL(released()),this,SLOT(handleButton()));
    QMetaObject::connectSlotsByName(this);
}

void MainWindow::setColori(){
    //definizione layout usati
    verticalLayout = new QVBoxLayout(coloriTab);
    buttonLayout = new QGridLayout();
    previewGroupBox = new QGroupBox(tr("Setting Color"));
    horizontalLayout = new QHBoxLayout(previewGroupBox);

    cDisplay = new colorDisplay(previewGroupBox);
    cDisplayAdd = new colorDisplay(previewGroupBox);




    //SETTING DEL BUTTON LAYOUT
    add = new QPushButton(tr("somma"));
    sottr = new QPushButton(tr("sottrai"));
    uguale = new QPushButton(tr("="));
    maggiore = new QPushButton(tr(">"));
    minore = new QPushButton(tr("<"));
    molt = new QPushButton(tr("moltiplica"));
    div = new QPushButton(tr("dividi"));

    //aggiungo i a BUTTON LAYOUT
    buttonLayout->addWidget(add,0,0);
    buttonLayout->addWidget(sottr,0,1);
    buttonLayout->addWidget(maggiore,0,2);
    buttonLayout->addWidget(minore,0,3);
    buttonLayout->addWidget(uguale,1,2,1,2);
    buttonLayout->addWidget(molt,1,0);
    buttonLayout->addWidget(div,1,1);

    //aggiungo il layout creato nel vertical layout
    horizontalLayout->addWidget(cDisplay);
    horizontalLayout->addWidget(cDisplayAdd);
    verticalLayout->addWidget(previewGroupBox);
    verticalLayout->addLayout(buttonLayout);

    disabilitaColor();
    creaConnect();

}

void MainWindow::setPaletteTab(){
    paletteW = new paletteWidget();
    paletteLayout = new QGridLayout(paletteTab);
    paletteLayout->addWidget(paletteW,0,0);

}

void MainWindow::setPixelArtTab(){
    pixelArtLayout = new QGridLayout(pixelartTab);
    pixelA = new pixelArtWidget();
    pixelArtLayout->addWidget(pixelA);
}


void MainWindow::disabilitaColor(){
    cDisplayAdd->setEnabled(false);
    uguale->setEnabled(false);
}

void MainWindow::abilitaColor(){
    cDisplayAdd->setEnabled(false);
    uguale->setEnabled(false);
}

void MainWindow::creaConnect(){
    //connect di tab colori
    connect(add,SIGNAL(clicked()),this,SLOT(mainControllerColori()));
    connect(sottr,SIGNAL(clicked()),this,SLOT(mainControllerColori()));
    connect(uguale,SIGNAL(clicked()),this,SLOT(mainControllerColori()));
    connect(maggiore,SIGNAL(clicked()),this,SLOT(mainControllerColori()));
    connect(minore,SIGNAL(clicked()),this,SLOT(mainControllerColori()));
    connect(molt,SIGNAL(clicked()),this,SLOT(mainControllerColori()));
    connect(div,SIGNAL(clicked()),this,SLOT(mainControllerColori()));
}

void MainWindow::mainControllerColori(){
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString pigiedValue = clickedButton->text();
    if(!(pigiedValue == QString("="))){
        op=pigiedValue;
        cDisplayAdd->setEnabled(true);
        uguale->setEnabled(true);
    }
    else{
        //fai operazioni
        Color primo(cDisplay->getRed(),cDisplay->getGreen(),cDisplay->getBlue(),255);
        Color secondo(cDisplayAdd->getRed(),cDisplayAdd->getGreen(),cDisplayAdd->getBlue(),255);
        Color risultato;
        if (op=="somma"){
            risultato = primo + secondo;
        }else if (op=="sottrai"){
            risultato = primo - secondo;
        }else if (op==">"){
            if(primo > secondo)
                risultato = primo;
            else
                risultato = secondo;
        }else if (op=="dividi"){
            try{
                risultato = primo / secondo;
            }catch(divisioneZero){
                QMessageBox Msgbox;
                Msgbox.setText("Non puoi dividere quando una coordinata RGB e' uguale a 0");
                Msgbox.exec();
                risultato = primo;
            }
        }else if (op=="moltiplica"){
            risultato = primo *secondo;
        }else {
            if(primo < secondo)
                risultato = primo;
            else
                risultato = secondo;
        }
        cDisplay->setRed(risultato.getRed());
        cDisplay->setGreen(risultato.getGreen());
        cDisplay->setBlue(risultato.getBlue());
        cDisplayAdd->setRed(255);
        cDisplayAdd->setGreen(255);
        cDisplayAdd->setBlue(255);
        cDisplayAdd->setEnabled(false);
        uguale->setEnabled(false);

    }
}


MainWindow::~MainWindow(){
    delete add;
    delete sottr;
    delete uguale;
    delete maggiore;
    delete minore;
    delete molt;
    delete div;
    delete pixelA;
    delete paletteW;
    delete cDisplay;
    delete cDisplayAdd;
    delete horizontalLayout;
    delete previewGroupBox;
    delete paletteLayout;
    delete buttonLayout;
    delete verticalLayout;
    delete coloriTab;
    delete paletteTab;
    delete pixelartTab;
    delete tabContainer;
    delete ui;
}
