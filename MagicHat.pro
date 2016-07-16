#-------------------------------------------------
#
# Project created by QtCreator 2016-07-03T19:19:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MagicHat
TEMPLATE = app


SOURCES += main.cpp\
        maindialog.cpp \
    frase.cpp \
    hat.cpp \
    loadfromxmltask.cpp

HEADERS  += maindialog.h \
    frase.h \
    hat.h \
    loadfromxmltask.h

FORMS    += maindialog.ui

LIBS += -lQtSpeech

INCLUDEPATH += "$$PWD/include/qtspeech"
LIBS += -L"$$PWD/lib"
