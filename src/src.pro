include(../defaults.pri)
QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

macx{
  TARGET = ../$${APP_NAME}
}
win32 {
  TARGET = ../$${APP_NAME}
}
unix:!macx {
  TARGET = $${APP_NAME}
}

CONFIG -= testlib
CONFIG += staticlib
TEMPLATE = lib

SOURCES  += source/mainwindow.cpp
HEADERS  += header/mainwindow.h \
            header/skiplist.h \
    header/entry.h
FORMS    += form/mainwindow.ui

QTPLUGIN += qsqlmysql
