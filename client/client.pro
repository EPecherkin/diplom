QT       += core network sql
QT       -= gui

TARGET   = client
TEMPLATE = app

CONFIG   += console
CONFIG   -= app_bundle

SOURCES  += *.cpp
HEADERS  += *.h

win32:DEFINES  += WIN32
unix:DEFINES   += UNIX

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
