include(../defaults.pri)
QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

win32 {
  TARGET = ../$${APP_NAME}
}
unix {
  TARGET = $${APP_NAME}
}

CONFIG -= testlib
CONFIG += staticlib
CONFIG += c++11

TEMPLATE = lib


SOURCES  += source/mainwindow.cpp \
    source/dbmanager.cpp \
    source/stadium.cpp \
    source/souvenir.cpp

HEADERS  += header/mainwindow.h \
    header/dbmanager.h \
    header/souvenir.h \
    header/stadium.h \
    header/skiplist.h \
    header/entry.h \
    header/graph.h \
    header/priorityqueue.h

FORMS    += form/mainwindow.ui

QTPLUGIN += qsqlmysql
