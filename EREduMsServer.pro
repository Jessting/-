#-------------------------------------------------
#
# Project created by QtCreator 2018-07-23T17:32:43
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EREduMsServer
TEMPLATE = app

INCLUDEPATH += $$PWD/include
include(Network/Network.pri)
include(DataBase/DataBase.pri)
include(Info/Info.pri)
include(Widget/Widget.pri)
include(Protocol/Protocol.pri)

SOURCES += main.cpp\
        logic.cpp

HEADERS  += logic.h

FORMS    +=

DISTFILES +=
