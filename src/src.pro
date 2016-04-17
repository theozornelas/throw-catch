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
TEMPLATE = lib

SOURCES  += source/mainwindow.cpp \
    source/dbmanager.cpp
HEADERS  += header/mainwindow.h \
    header/dbmanager.h
FORMS    += form/mainwindow.ui

QTPLUGIN += qsqlmysql
