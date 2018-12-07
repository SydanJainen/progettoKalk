#ifndef COLORCARD_H
#define COLORCARD_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVariant>

class colorCard : public QWidget
{
    Q_OBJECT
public:
    explicit colorCard(QWidget *parent = 0);
    void setColor(int r, int g, int b);
    void setProp(int r,int g,int b);
    ~colorCard();
    QPushButton *modifica , *rimuovi;
signals:

public slots:
    void setBianco();
    void setText();

private:
    QLabel *colorLabel;
    QVBoxLayout *verticalLayout;
    QPalette palette;
    QColor *visualColor=0;
};

#endif // COLORCARD_H
