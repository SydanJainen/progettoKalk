#-------------------------------------------------
#
# Project created by QtCreator 2018-07-06T15:55:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kalk
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        view/mainwindow.cpp \
    view/colordisplay.cpp \
    view/palettewidget.cpp \
    view/pixelArtWidget.cpp \
    model/color.cpp \
    model/colorgroup.cpp \
    model/palette.cpp \
    model/pixelart.cpp\
    model/imgspeculare.cpp \
    view/displaypalette.cpp \
    view/colorcard.cpp

HEADERS  += view/mainwindow.h \
    view/colordisplay.h \
    view/palettewidget.h \
    view/pixelArtWidget.h \
    model/color.h \
    model/colorgroup.h\
    model/palette.h \
    model/pixelart.h\
    model/imgspeculare.h \
    view/displaypalette.h \
    view/colorcard.h

FORMS    += mainwindow.ui
