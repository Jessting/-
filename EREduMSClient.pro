#-------------------------------------------------
#
# Project created by QtCreator 2018-07-25T20:01:02
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EREduMSClient
TEMPLATE = app

INCLUDEPATH += $$PWD/include
include(Network/Network.pri)
include(Protocol/Protocol.pri)
include(Info/Info.pri)
include(Widgets/Widgets.pri)
include(Manage/Manage.pri)

SOURCES += main.cpp\
        logic.cpp

HEADERS  += logic.h

