#include "colordisplay.h"

colorDisplay::colorDisplay(QWidget *parent) : QWidget(parent){
    sliderLayout = new QGridLayout(this);
    horizontalLayout = new QHBoxLayout();
    buttonLayout = new QGridLayout();
    for (int j=0 ; j<4;j++){
        sliderLayout->setColumnMinimumWidth(j,120);
    }

    //SETTING DELLO SLIDER LAYOUT
    rSlider = new QSlider();
    rSlider->setOrientation(Qt::Horizontal);
    gSlider = new QSlider();
    gSlider->setOrientation(Qt::Horizontal);
    bSlider = new QSlider();
    bSlider->setOrientation(Qt::Horizontal);

    redLabel = new QLabel(tr("red"));
    greenLabel = new QLabel(tr("green"));
    blueLabel = new QLabel(tr("blue"));
    hexLabel = new QLabel(tr("HEX  #"));
    labelColor = new QLabel(tr("Colore :"));

    colorLabel = new QLabel(tr("Colore"));
    setColor(0,0,0);
    //colorLabel->setGeometry(QRect(0,0,40,40));




    //QLineEdit
    redLine = new QSpinBox();
    greenLine =new QSpinBox();
    blueLine = new QSpinBox();
    hexLine = new QLineEdit(0);




    sliderLayout->addWidget(redLabel,0,0);
    sliderLayout->addWidget(greenLabel,1,0);
    sliderLayout->addWidget(blueLabel ,2,0);
    sliderLayout->addWidget(rSlider,0,2,1,2);
    sliderLayout->addWidget(gSlider ,1,2,1,2);
    sliderLayout->addWidget(bSlider,2,2,1,2);
    sliderLayout->addWidget(redLine,0,1);
    sliderLayout->addWidget(greenLine,1,1);
    sliderLayout->addWidget(blueLine,2,1);
    sliderLayout->addWidget(hexLabel ,3,0);
    sliderLayout->addWidget(hexLine ,3 ,1);
    sliderLayout->addWidget(labelColor ,5,0);
    sliderLayout->addWidget(colorLabel ,5,1,1,4);



    primoC = new QPushButton();
    secondoC = new QPushButton();
    terzoC = new QPushButton();
    quartoC = new QPushButton();
    quintoC = new QPushButton();
    horizontalLayout->addWidget(primoC);
    horizontalLayout->addWidget(secondoC);
    horizontalLayout->addWidget(terzoC);
    horizontalLayout->addWidget(quartoC);
    horizontalLayout->addWidget(quintoC);

     //addo pulsanti

    complementare = new QPushButton(tr("Complementare"));
    wavelength = new QPushButton(tr("Wavelength"));
    Analogo = new QPushButton(tr("Analogo"));
    Triade= new QPushButton(tr("Triade"));
    Tetrade = new QPushButton(tr("Tetrade"));
    Desaturazione = new QPushButton(tr("Desat"));
    wave = new QSpinBox();
    wave->setValue(380);
    line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    hexLine->setReadOnly(true);


    //aggiungo i a BUTTON LAYOUT
    buttonLayout->addWidget(complementare,0,0);
    buttonLayout->addWidget(Analogo,3,0);
    buttonLayout->addWidget(Triade,3,1);
    buttonLayout->addWidget(Tetrade,3,2);
    buttonLayout->addWidget(Desaturazione,0,1);
    buttonLayout->addWidget(wavelength,4,0);
    buttonLayout->addWidget(wave,4,1);
    buttonLayout->addLayout(horizontalLayout,2,0,1,3);
    buttonLayout->addWidget(line,1,0,1,3);
    sliderLayout->addLayout(buttonLayout,6,0,1,4);

    setPalette(*primoC,255,0,0);
    setPalette(*secondoC,0,255,0);
    setPalette(*terzoC,0,0,255);
    setPalette(*quartoC,0,0,0);
    setPalette(*quintoC,255,255,255);

    setMaxRange();
    createToolTipPushButton();
    //creo connessioni
    creaConnect();
}

void colorDisplay::setMaxRange(){
    rSlider->setRange(0,255);
    gSlider->setRange(0,255);
    bSlider->setRange(0,255);
    redLine->setRange(0,255);
    greenLine->setRange(0,255);
    blueLine->setRange(0,255);
    wave->setRange(380,750);


}

void colorDisplay::setColor(int r,int g,int b){
        if(visualColor!= nullptr) delete visualColor;
        visualColor = new QColor(r,g,b);
        palette = colorLabel->palette();
        palette.setColor(colorLabel->backgroundRole(), *visualColor);
        palette.setColor(colorLabel->foregroundRole(),*visualColor);
        colorLabel->setPalette(palette);
        colorLabel->setAutoFillBackground(true);
        //delete visualColor;
}

int colorDisplay::getRed(){
    return redLine->value();
}

int colorDisplay::getGreen(){
    return greenLine->value();
}

int colorDisplay::getBlue(){
    return blueLine->value();
}

void colorDisplay::setRed(int value){
    redLine->setValue(value);
}

void colorDisplay::setGreen(int value){
    greenLine->setValue(value);
}
void colorDisplay::setBlue(int value){
    blueLine->setValue(value);
}

void colorDisplay::updateColorRed(int value){
    setColor(value,visualColor->green(),visualColor->blue());
}

void colorDisplay::updateColorGreen(int value){
    setColor(visualColor->red(),value,visualColor->blue());
}

void colorDisplay::updateColorBlue(int value){
    setColor(visualColor->red(),visualColor->green(),value);
}

void colorDisplay::createToolTipPushButton(){
    wavelength->setToolTip(tr("Wavelenght"));
    complementare->setToolTip(tr("Complementare"));
    Analogo->setToolTip(tr("Analogo"));
    Triade->setToolTip(tr("Triade"));
    Tetrade->setToolTip(tr("Tetrade"));
    Desaturazione->setToolTip(tr("Desaturazione"));
    wave->setToolTip(tr("Range tra 380 e 750"));
}

void colorDisplay::setPalette(QPushButton& bottone , int r, int g , int b){
    pal =bottone.palette();
    pal.setColor(bottone.backgroundRole(), QColor(r,g,b));
    pal.setColor(bottone.foregroundRole(), QColor(r,g,b));
    bottone.setAutoFillBackground(true);
    bottone.setPalette(pal);
    bottone.update();
    bottone.setFlat(true);
    bottone.setProperty("red",QVariant(r));
    bottone.setProperty("blue",QVariant(b));
    bottone.setProperty("green",QVariant(g));
}


void colorDisplay::unaryController(){
    int vred = getRed();
    int vgreen = getGreen();
    int vblue = getBlue();
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString pigiedValue = clickedButton->text();
    colorDaGestire = new Color(vred,vgreen,vblue,255);
    if(pigiedValue ==QString("Complementare")){
        *colorDaGestire = colorDaGestire->Complementare();
        rSlider->setValue(colorDaGestire->getRed());
        gSlider->setValue(colorDaGestire->getGreen());
        bSlider->setValue(colorDaGestire->getBlue());
    }else if(pigiedValue==QString("Wavelength")){
        int val = wave->value();
        Color ritorno = colorDaGestire->wavelength(val);
        rSlider->setValue(ritorno.getRed());
        gSlider->setValue(ritorno.getGreen());
        bSlider->setValue(ritorno.getBlue());

    }else if(pigiedValue==QString("Analogo")){
        std::vector<Color> analoghi = colorDaGestire->Analogo();
        setPalette(*primoC,255,255,255);
        setPalette(*secondoC,255,255,255);
        setPalette(*terzoC,255,255,255);
        setPalette(*quartoC,255,255,255);
        setPalette(*quintoC,255,255,255);
        setPalette(*primoC,analoghi[0].getRed(),analoghi[0].getGreen(),analoghi[0].getBlue());
        setPalette(*secondoC,analoghi[1].getRed(),analoghi[1].getGreen(),analoghi[1].getBlue());
        setPalette(*terzoC,analoghi[2].getRed(),analoghi[2].getGreen(),analoghi[2].getBlue());
        setPalette(*quartoC,analoghi[3].getRed(),analoghi[3].getGreen(),analoghi[3].getBlue());
        setPalette(*quintoC,analoghi[4].getRed(),analoghi[4].getGreen(),analoghi[4].getBlue());

    }else if(pigiedValue==QString("Triade")){
        std::vector<Color> analoghi = colorDaGestire->Triade();
        setPalette(*primoC,255,255,255);
        setPalette(*secondoC,255,255,255);
        setPalette(*terzoC,255,255,255);
        setPalette(*quartoC,255,255,255);
        setPalette(*quintoC,255,255,255);
        setPalette(*primoC,analoghi[0].getRed(),analoghi[0].getGreen(),analoghi[0].getBlue());
        setPalette(*secondoC,analoghi[1].getRed(),analoghi[1].getGreen(),analoghi[1].getBlue());
        setPalette(*terzoC,analoghi[2].getRed(),analoghi[2].getGreen(),analoghi[2].getBlue());
        setPalette(*quartoC,255,255,255);
        setPalette(*quintoC,255,255,255);

    }else if(pigiedValue==QString("Tetrade")){
        std::vector<Color> analoghi = colorDaGestire->Tetrade();
        setPalette(*primoC,255,255,255);
        setPalette(*secondoC,255,255,255);
        setPalette(*terzoC,255,255,255);
        setPalette(*quartoC,255,255,255);
        setPalette(*quintoC,255,255,255);
        setPalette(*primoC,analoghi[0].getRed(),analoghi[0].getGreen(),analoghi[0].getBlue());
        setPalette(*secondoC,analoghi[1].getRed(),analoghi[1].getGreen(),analoghi[1].getBlue());
        setPalette(*terzoC,analoghi[2].getRed(),analoghi[2].getGreen(),analoghi[2].getBlue());
        setPalette(*quartoC,analoghi[3].getRed(),analoghi[3].getGreen(),analoghi[3].getBlue());
        setPalette(*quintoC,255,255,255);

    }else if(pigiedValue==QString("Desat")){
        *colorDaGestire = colorDaGestire->Desaturazione();
        rSlider->setValue(colorDaGestire->getRed());
        gSlider->setValue(colorDaGestire->getGreen());
        bSlider->setValue(colorDaGestire->getBlue());
    }
    delete(colorDaGestire);
    clickedButton=0;
}


void colorDisplay::generateHEX(){

    int vred = getRed();
    int vgreen = getGreen();
    int vblue = getBlue();
    Color hexC (vred,vgreen,vblue);
    hexLine->clear();
    hexLine->setText(QString::fromStdString(hexC.toHEX()));

}


void colorDisplay::updateView(){
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    rSlider->setValue((clickedButton->property("red")).toInt());
    gSlider->setValue((clickedButton->property("green")).toInt());
    bSlider->setValue((clickedButton->property("blue")).toInt());

}



void colorDisplay::creaConnect(){
    connect(rSlider,SIGNAL(valueChanged(int)),redLine,SLOT(setValue(int)));
    connect(gSlider,SIGNAL(valueChanged(int)),greenLine,SLOT(setValue(int)));
    connect(bSlider,SIGNAL(valueChanged(int)),blueLine,SLOT(setValue(int)));
    connect(redLine,SIGNAL(valueChanged(int)),rSlider ,SLOT(setValue(int)));
    connect(greenLine,SIGNAL(valueChanged(int)),gSlider ,SLOT(setValue(int)));
    connect(blueLine,SIGNAL(valueChanged(int)),bSlider ,SLOT(setValue(int)));
    connect(rSlider,SIGNAL(valueChanged(int)),this,SLOT(updateColorRed(int)));
    connect(gSlider,SIGNAL(valueChanged(int)),this,SLOT(updateColorGreen(int)));
    connect(bSlider,SIGNAL(valueChanged(int)),this,SLOT(updateColorBlue(int)));
    connect(redLine,SIGNAL(valueChanged(int)),this,SLOT(updateColorRed(int)));
    connect(greenLine,SIGNAL(valueChanged(int)),this,SLOT(updateColorGreen(int)));
    connect(blueLine,SIGNAL(valueChanged(int)),this,SLOT(updateColorBlue(int)));
    connect(complementare,SIGNAL(clicked()),this,SLOT(unaryController()));
    connect(wavelength,SIGNAL(clicked()),this,SLOT(unaryController()));
    connect(Analogo,SIGNAL(clicked()),this,SLOT(unaryController()));
    connect(Triade,SIGNAL(clicked()),this,SLOT(unaryController()));
    connect(Tetrade,SIGNAL(clicked()),this,SLOT(unaryController()));
    connect(Desaturazione,SIGNAL(clicked()),this,SLOT(unaryController()));
    //connect(display,SIGNAL(clicked()),this,SLOT(hexconverterController()));
    connect(primoC,SIGNAL(clicked()),this,SLOT(updateView()));
    connect(secondoC,SIGNAL(clicked()),this,SLOT(updateView()));
    connect(terzoC,SIGNAL(clicked()),this,SLOT(updateView()));
    connect(quartoC,SIGNAL(clicked()),this,SLOT(updateView()));
    connect(quintoC,SIGNAL(clicked()),this,SLOT(updateView()));
    //connect(generate,SIGNAL(clicked()),this,SLOT(generateHEX()));
    connect(rSlider,SIGNAL(valueChanged(int)),this,SLOT(generateHEX()));
    connect(gSlider,SIGNAL(valueChanged(int)),this,SLOT(generateHEX()));
    connect(bSlider,SIGNAL(valueChanged(int)),this,SLOT(generateHEX()));

}

colorDisplay::~colorDisplay(){
    delete(line);
    delete(rSlider);
    delete(gSlider);
    delete(bSlider);
    delete(redLabel);
    delete(labelColor);
    delete(greenLabel);
    delete(blueLabel);
    delete(hexLabel);
    delete(colorLabel);
    delete(redLine);
    delete(greenLine);
    delete(blueLine);
    delete(hexLine);
    delete(complementare);
    delete(wavelength);
    delete(Analogo);
    delete(Triade);
    delete(Tetrade);
    delete(visualColor);
    delete(primoC);
    delete(secondoC);
    delete(terzoC);
    delete(quartoC);
    delete(quintoC);
    delete(horizontalLayout);
    delete(buttonLayout);
    delete(sliderLayout);
}
