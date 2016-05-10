#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T09:26:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += network

TARGET = PhoneAttackTools
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    attackthread.cpp \
    networkutill.cpp \
    loadinterface.cpp

HEADERS  += mainwindow.h \
    attackthread.h \
    networkutill.h \
    loadinterface.h

FORMS    += mainwindow.ui

QT += network

