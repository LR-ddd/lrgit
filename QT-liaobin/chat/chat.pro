#-------------------------------------------------
#
# Project created by QtCreator 2020-06-23T11:02:43
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chat
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    interface.cpp \
    regi.cpp

HEADERS  += widget.h \
    interface.h \
    regi.h

FORMS    += widget.ui \
    interface.ui \
    regi.ui

RESOURCES += \
    pic.qrc \
    backgroud.qrc
