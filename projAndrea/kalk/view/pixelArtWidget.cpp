#include "pixelArtWidget.h"

pixelArtWidget::pixelArtWidget(QWidget *parent) : QWidget(parent)
{
    pixelArtLayout =new QGridLayout(this);

    create8 = new QPushButton(tr("clean"));
    findReplace = new QPushButton(tr("trova e rimuovi"));
    add = new QPushButton(tr("add"));
    desat = new QPushButton(tr("desat"));
    comp = new QPushButton(tr("complem"));
    flipX = new QPushButton(tr("flipX"));
    flipY = new QPushButton(tr("flipY"));
    colore = new colorDisplay();
    scambiaH = new QPushButton(tr("scambia H"));
    scambiaV = new QPushButton(tr("scambia V"));
    inserisci = new QPushButton(tr("Inserisci"));
    riga = new QLabel(tr("riga :"));
    colonna = new QLabel(tr("colonna :"));
    rigaLine = new QLineEdit(tr("0"));
    colonnaLine = new QLineEdit(tr("0"));
    spec = new QPushButton(tr("Abilita Speculare"));

    pixelArtLayout->addWidget(scambiaV, 4,0);
    pixelArtLayout->addWidget(findReplace,3,0);
    pixelArtLayout->addWidget(create8,2,1);
    pixelArtLayout->addWidget(add,2,0);
    pixelArtLayout->addWidget(scambiaH,4,1);
    pixelArtLayout->addWidget(comp,3,1);
    pixelArtLayout->addWidget(desat,2,2);
    pixelArtLayout->addWidget(colore,0,5,4,2);
    pixelArtLayout->addWidget(inserisci,4,5,1,2);
    pixelArtLayout->addWidget(riga,1,0);
    pixelArtLayout->addWidget(rigaLine,1,1);
    pixelArtLayout->addWidget(colonna,1,2);
    pixelArtLayout->addWidget(colonnaLine,1,3);
    pixelArtLayout->addWidget(spec,2,3,3,1);
    pixelArtLayout->addWidget(flipX,3,2);
    pixelArtLayout->addWidget(flipY,4,2);
    minColumnW(150);

    matrice = new QTableWidget(8,8);

    disabilitaSpec();
    createMatrix(8,8);
    creaConnect();

    pixelArtLayout->addWidget(matrice,0,0,1,5);
}

void pixelArtWidget::minColumnW(int value){
    for (int i=0;i<pixelArtLayout->columnCount();i++){
        pixelArtLayout->setColumnMinimumWidth(i,value);
    }
}

void pixelArtWidget::creaConnect(){
    connect(matrice,SIGNAL(itemClicked(QTableWidgetItem*)),this,SLOT(clickedController(QTableWidgetItem*)));
    connect(colore->rSlider,SIGNAL(valueChanged(int)),this,SLOT(updateInserisciRed(int)));
    connect(colore->gSlider,SIGNAL(valueChanged(int)),this,SLOT(updateInserisciGreen(int)));
    connect(colore->bSlider,SIGNAL(valueChanged(int)),this,SLOT(updateInserisciBlue(int)));
    connect(inserisci,SIGNAL(clicked()),this,SLOT(mainControllerPixelArt()));
    connect(add,SIGNAL(clicked()),this,SLOT(mainControllerPixelArt()));
    connect(comp,SIGNAL(clicked()),this,SLOT(mainControllerPixelArt()));
    connect(desat,SIGNAL(clicked()),this,SLOT(mainControllerPixelArt()));
    connect(findReplace,SIGNAL(clicked()),this,SLOT(mainControllerPixelArt()));
    connect(create8,SIGNAL(clicked()),this,SLOT(mainControllerPixelArt()));
    connect(scambiaH,SIGNAL(clicked()),this,SLOT(mainControllerPixelArt()));
    connect(scambiaV,SIGNAL(clicked()),this,SLOT(mainControllerPixelArt()));
    connect(spec,SIGNAL(clicked()),this,SLOT(mainControllerPixelArt()));
    connect(flipY,SIGNAL(clicked()),this,SLOT(mainControllerPixelArt()));
    connect(flipX,SIGNAL(clicked()),this,SLOT(mainControllerPixelArt()));
}

void pixelArtWidget::clickedController(QTableWidgetItem* item){
    QColor ad = (item->data(Qt::BackgroundRole)).value<QColor>();
    colore->setRed(ad.red());
    colore->setGreen(ad.green());
    colore->setBlue(ad.blue());
    inserisci->setProperty("red",QVariant(ad.red()));
    inserisci->setProperty("green",QVariant(ad.green()));
    inserisci->setProperty("blue",QVariant(ad.blue()));
    rigaLine->setText(QString::number(item->row()));
    colonnaLine->setText((QString::number(item->column())));
}

void pixelArtWidget::updateInserisciRed(int value){
    inserisci->setProperty("red",QVariant(value));
}

void pixelArtWidget::updateInserisciGreen(int value){
    inserisci->setProperty("green",QVariant(value));
}

void pixelArtWidget::updateInserisciBlue(int value){
    inserisci->setProperty("blue",QVariant(value));
}

void pixelArtWidget::mainControllerPixelArt(){
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString pigiedValue = clickedButton->text();
    oggetto = new pixelArt(8);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            QColor a =getColore(i,j);
            static_cast<pixelArt*>(oggetto)->addColore(Color(a.red(),a.green(),a.blue()),i,j);
        }
    }
    //check su tipo di pixelArt
    if(dynamic_cast<pixelArt*>(oggetto)){
        if(spec->text()==QString("Disabilita Speculare")){
            try{
                imgSpeculare* appoggio = new imgSpeculare(*(static_cast<pixelArt*>(oggetto)));
                delete oggetto;
                oggetto=appoggio;
                appoggio=0;

            }
            catch(noSpeculare){
                QMessageBox message;
                message.setText(tr("La immagine di partenza non e' piu' speculare. Modalita Speculare disattivata"));
                message.exec();
                disabilitaSpec();
            }
        }
        if(pigiedValue==QString("trova e rimuovi")){
            oggetto->findReplace(Color((inserisci->property("red")).toInt(),(inserisci->property("green")).toInt(),(inserisci->property("blue")).toInt()),Color(0));
            setMatrixLayout(oggetto);
        }
        if(pigiedValue==QString("add")){
            oggetto->add(Color((inserisci->property("red")).toInt(),(inserisci->property("green")).toInt(),(inserisci->property("blue")).toInt()));
            setMatrixLayout(oggetto);
        }
        if(pigiedValue==QString("desat")){
            oggetto->desat();
            setMatrixLayout(oggetto);
        }
        if(pigiedValue==QString("complem")){
            oggetto->complementare();
            setMatrixLayout(oggetto);
        }
        if(pigiedValue==QString("scambia V")){
            static_cast<pixelArt*>(oggetto)->scambiaVert();
            setMatrixLayout(oggetto);
        }
        if(pigiedValue==QString("scambia H")){
            static_cast<pixelArt*>(oggetto)->scambiaOrizz();
            setMatrixLayout(oggetto);
        }
        if(pigiedValue==QString("Inserisci")){
            insertColor((rigaLine->text()).toInt(),(colonnaLine->text()).toInt(),Color(inserisci->property("red").toInt(),inserisci->property("green").toInt(),inserisci->property("blue").toInt()));
        }
        if(pigiedValue==QString("clean")){
            createMatrix(8,8);
        }
        if (pigiedValue==QString("Inserisci Speculare")){
            if(dynamic_cast<imgSpeculare*>(oggetto)){
                static_cast<imgSpeculare*>(oggetto)->addColore(Color(inserisci->property("red").toInt(),inserisci->property("green").toInt(),inserisci->property("blue").toInt()),(rigaLine->text()).toInt(),(colonnaLine->text()).toInt());
                setMatrixLayout(oggetto);
            }
            else{
                disabilitaSpec();
            }
        }
        if (pigiedValue==QString("flipX")){
            if(dynamic_cast<imgSpeculare*>(oggetto)){
                static_cast<imgSpeculare*>(oggetto)->flipX();
                setMatrixLayout(oggetto);
            }
            else{
                disabilitaSpec();
            }
        }
        if (pigiedValue==QString("flipY")){
            if(dynamic_cast<imgSpeculare*>(oggetto)){
                static_cast<imgSpeculare*>(oggetto)->flipY();
                setMatrixLayout(oggetto);
            }
            else{
                disabilitaSpec();
            }
        }
        if(pigiedValue==QString("Abilita Speculare")){
            try{
                imgSpeculare img((*(static_cast<pixelArt*>(oggetto))));
                abilitaSpec();

            }catch(noSpeculare){
                QMessageBox message;
                message.setText(tr("La immagine non e' speculare"));
                message.exec();

            }
        }
        if(pigiedValue==QString("Disabilita Speculare")){
           disabilitaSpec();
        }
    }
    clickedButton=0;
    delete oggetto;
}

void pixelArtWidget::abilitaSpec(){
    spec->setText("Disabilita Speculare");
    inserisci->setText("Inserisci Speculare");
    flipY->setEnabled(true);
    flipX->setEnabled(true);
}

void pixelArtWidget::disabilitaSpec(){
    spec->setText("Abilita Speculare");
    inserisci->setText("Inserisci");
    flipY->setEnabled(false);
    flipX->setEnabled(false);
}

void pixelArtWidget::setMatrixLayout(ColorGroup* oggetto){
    if(dynamic_cast<pixelArt*>(oggetto)){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                insertColor(i,j,static_cast<pixelArt*>(oggetto)->getElement(i,j));
            }
        }
    }
}

QColor pixelArtWidget::getColore(int i,int j){
     QColor ad = (matrice->item(i,j)->data(Qt::BackgroundRole)).value<QColor>();
     return ad;
}

void pixelArtWidget::insertColor(int x, int y,Color a){
     QTableWidgetItem* item =new QTableWidgetItem();
     item->setData(Qt::BackgroundRole,QColor(a.getRed(),a.getGreen(),a.getBlue()));
     matrice->removeCellWidget(x,y);
     matrice->setItem(x, y,item);
}

void pixelArtWidget::createMatrix(int n, int m){
    int max = (n>m)?n:m;
    for(int i=0;i<=n;i++){
        matrice->setRowHeight(i,500/max);
        for(int j=0;j<=m;j++){
            matrice->setColumnWidth(j,500/max);
            insertColor(i,j,Color(0));
        }
    }
}

pixelArtWidget::~pixelArtWidget(){
    matrice->clear();
    delete flipX;
    delete flipY;
    delete create8;
    delete findReplace;
    delete add;
    delete desat;
    delete comp;
    delete scambiaH;
    delete scambiaV;
    delete inserisci;
    delete colonna ;
    delete riga;
    delete rigaLine;
    delete colonnaLine;
    delete spec;
    delete colore;
    delete matrice;
    delete pixelArtLayout;
}
