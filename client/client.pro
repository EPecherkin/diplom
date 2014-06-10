QT       += core gui network sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = client
TEMPLATE = app

SOURCES  += \
    desktopservice.cpp \
    main.cpp \
    server.cpp \
    storage.cpp \
    gui/logindialog.cpp \
    gui/mainwindow.cpp \
    gui/computerswidget.cpp \
    gui/exportwidget.cpp \
    gui/statisticswidget.cpp \
    gui/usereditdialog.cpp \
    exporter.cpp
HEADERS  += \
    desktopservice.h \
    keylogger.h \
    macros.h \
    server.h \
    storage.h \
    gui/logindialog.h \
    gui/mainwindow.h \
    gui/computerswidget.h \
    gui/exportwidget.h \
    gui/statisticswidget.h \
    gui/usereditdialog.h \
    exporter.h
FORMS    += \
    gui/logindialog.ui \
    gui/mainwindow.ui \
    gui/computerswidget.ui \
    gui/exportwidget.ui \
    gui/statisticswidget.ui \
    gui/usereditdialog.ui

RESOURCES += \
    resources.qrc

win32:SOURCES  += keyloggerwindows.cpp
unix:DEFINES   += keyloggerunix.cpp

CONFIG(debug, debug|release): {
  DEFINES += DB_PATH=QString(\\\":memory:\\\")
#  win32:DEFINES += DB_PATH=QString(\\\"d:/archives/education/evm/evm_5/!diplom/keylogger_db/$$TARGET.sqlite3\\\")
#  unix:DEFINES += DB_PATH=QString(\\\"/other/archives/education/evm/evm_5/!diplom/keylogger_db/$$TARGET.sqlite3\\\")
}
CONFIG(release, debug|release): {
  DEFINES += DB_PATH=QString(\\\"./$$TARGET.sqlite3\\\")
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
