#ifndef QDISPLAYCOLOR_H
#define QDISPLAYCOLOR_H

#include <QMainWindow>
#include <QtWidgets>

class QDisplayColor : public QMainWindow
{
    Q_OBJECT
public:
    explicit QDisplayColor(QWidget *parent = 0);
    void setMaxSlider();
    void setMinSlider();

signals:

public slots:

signals:

public slots:

private:
    QHBoxLayout *horizontalLayout;
    QGridLayout *sliderLayout;


    //var per slider
    QSlider *rSlider , *gSlider , *bSlider;
    QLabel *redLabel , *greenLabel , *blueLabel , *hexLabel , *hLabel ;
    QLineEdit *redLine , *greenLine , *blueLine , *hexLine ,*hLine , *sLine , *vLine;



};

#endif // QDISPLAYCOLOR_H
