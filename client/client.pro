QT       += core gui network sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = client
TEMPLATE = app

CONFIG += console

SOURCES  += \
    desktopservice.cpp \
    main.cpp \
    server.cpp \
    storage.cpp \
    gui/logindialog.cpp \
    gui/mainwindow.cpp
HEADERS  += \
    desktopservice.h \
    keylogger.h \
    macros.h \
    server.h \
    storage.h \
    gui/logindialog.h \
    gui/mainwindow.h
FORMS    += \
    gui/logindialog.ui \
    gui/mainwindow.ui

RESOURCES += \
    resources.qrc

win32:SOURCES  += keyloggerwindows.cpp
unix:DEFINES   += keyloggerunix.cpp

debug: {
  win32:DEFINES += DB_PATH=QString(\\\"d:/archives/education/evm/evm_5/!diplom/keylogger_db/client.sqlite3\\\")
  unix:DEFINES += DB_PATH=QString(\\\"/other/archives/education/evm/evm_5/!diplom/keylogger_db/client.sqlite3\\\")
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/qdjango/r/ -lqdjango-db0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/qdjango/d/ -lqdjango-db0
else:unix: LIBS += -L$$PWD/../lib/qdjango/ -lqdjango-db

INCLUDEPATH += $$PWD/../lib/qdjango
DEPENDPATH  += $$PWD/../lib/qdjango

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../model/release/ -lmodel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../model/debug/ -lmodel
else:unix: LIBS += -L$$OUT_PWD/../model/ -lmodel

INCLUDEPATH += $$PWD/../model
DEPENDPATH  += $$PWD/../model

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/qjsonrpc/r/ -lqjsonrpc1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/qjsonrpc/d/ -lqjsonrpc1
else:unix: LIBS += -L$$PWD/../lib/qjsonrpc/ -lqjsonrpc

INCLUDEPATH += $$PWD/../lib/qjsonrpc
DEPENDPATH  += $$PWD/../lib/qjsonrpc
