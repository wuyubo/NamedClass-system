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
    qexcelobject.cpp \
    naming.cpp \
    classnames.cpp

HEADERS  += mainwidget.h \
    qexcelobject.h \
    naming.h \
    types.h \
    classnames.h

FORMS    += mainwidget.ui \
    naming.ui
