#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <view/colordisplay.h>
#include <view/palettewidget.h>
#include <view/pixelArtWidget.h>


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    //setter pagine tab
    void setColori();
    void setPaletteTab();
    void setPixelArtTab();
    void disabilitaColor();
    void abilitaColor();
    void creaConnect();


    //setterMenu

    //distruttore
    ~MainWindow();



private slots:
    //slot pixelArtTab
    void mainControllerColori();


private:
    Ui::MainWindow *ui;
    QTabWidget *tabContainer;
    QWidget *coloriTab, *paletteTab, *pixelartTab;

    //var per layout
    QVBoxLayout *verticalLayout;
    QGridLayout *buttonLayout , *paletteLayout , *pixelArtLayout;
    QHBoxLayout *horizontalLayout;

    //bottoni griglia
    QPushButton *add ,*sottr , *uguale , *maggiore , *minore , *molt ,*div ;
    colorDisplay *cDisplay , *cDisplayAdd;
    QGroupBox *previewGroupBox;


    //variabili per pixelArtTab

    pixelArtWidget *pixelA;


    //variabili per palette
    paletteWidget *paletteW;

    //controller variabili
    QString op;

};



#endif // MAINWINDOW_H
