QT       += core
QT       += network
QT       += positioning
QT       -= gui

TARGET = teste
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myudp.cpp

HEADERS += \
    myudp.h
