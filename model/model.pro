QT       += sql
QT       -= gui

TARGET   = model
TEMPLATE = lib

DEFINES  += MODEL_LIBRARY

SOURCES  += *.cpp
HEADERS  += *.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/qdjango/r/ -lqdjango-db0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/qdjango/d/ -lqdjango-db0
else:unix: LIBS += -L$$PWD/../lib/qdjango/ -lqdjango-db

INCLUDEPATH += $$PWD/../lib/qdjango
DEPENDPATH  += $$PWD/../lib/qdjango
