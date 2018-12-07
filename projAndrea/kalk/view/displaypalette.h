#ifndef DISPLAYPALETTE_H
#define DISPLAYPALETTE_H

#include <QWidget>
#include <QGroupBox>
#include "view/colorcard.h"

class displayPalette : public QWidget
{
    Q_OBJECT
public:
    explicit displayPalette(QWidget *parent = 0);
    colorCard *primo , *secondo , *terzo , *quarto , *quinto;
    ~displayPalette();
signals:

public slots:

private:
    QHBoxLayout *horiLayout;
    QGroupBox *group;
};

#endif // DISPLAYPALETTE_H
