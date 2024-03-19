#-------------------------------------------------
#
# Project created by QtCreator 2022-04-25T00:13:53
#
#-------------------------------------------------

QT       += core gui
QT       += core gui multimedia
CONFIG += resources_big

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    mypushbutton.cpp \
    choose.cpp \
    myitem.cpp \
    player.cpp \
    plant.cpp \
    enemy.cpp \
    game_map.cpp \
    play_scene.cpp \
    pea.cpp \
    chanzi.cpp \
    obstocal.cpp \
    sun.cpp \
    shop.cpp \
    enemy_pea.cpp

HEADERS  += mainwindow.h \
    mypushbutton.h \
    choose.h \
    myitem.h \
    player.h \
    plant.h \
    enemy.h \
    game_map.h \
    play_scene.h \
    pea.h \
    chanzi.h \
    obstocal.h \
    sun.h \
    shop.h \
    enemy_pea.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
