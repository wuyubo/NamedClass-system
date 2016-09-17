#-------------------------------------------------
#
# Project created by QtCreator 2016-09-13T10:33:07
#
#-------------------------------------------------

QT       += core gui
QT       += axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NamedClasses
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    naming.cpp \
    classnames.cpp \
    excel/qexcel.cpp

HEADERS  += mainwidget.h \
    naming.h \
    types.h \
    classnames.h \
    excel/qexcel.h

FORMS    += mainwidget.ui \
    naming.ui
