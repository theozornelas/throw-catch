INCLUDEPATH += $$PWD/src
INCLUDEPATH += $$PWD/src/header
INCLUDEPATH += $$PWD/src/source
INCLUDEPATH += $$PWD/src/form

APP_NAME = throw-catch
SRC_DIR = $$PWD

SUBDIRS += \
    $$PWD/app/app.pro
    $$PWD/src/src.pro
    $$PWD/test/test.pro
