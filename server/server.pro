QT       += core network sql
QT       -= gui

TARGET   = server
TEMPLATE = app

CONFIG   += console
CONFIG   -= app_bundle

SOURCES  += *.cpp
HEADERS  += *.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/qjsonrpc/r/ -lqjsonrpc1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/qjsonrpc/d/ -lqjsonrpc1
else:unix: LIBS += -L$$PWD/../lib/qjsonrpc/ -lqjsonrpc1

INCLUDEPATH += $$PWD/../lib/qjsonrpc
DEPENDPATH  += $$PWD/../lib/qjsonrpc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../model/release/ -lmodel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../model/debug/ -lmodel
else:unix: LIBS += -L$$OUT_PWD/../model/ -lmodel

INCLUDEPATH += $$PWD/../model
DEPENDPATH  += $$PWD/../model
