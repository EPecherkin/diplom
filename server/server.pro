QT       += core gui network sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = server
TEMPLATE = app

SOURCES += \
    main.cpp \
    desktopservice.cpp \
    rpcservice.cpp \
    gui/computerswidget.cpp \
    gui/exportwidget.cpp \
    gui/groupeditdialog.cpp \
    gui/groupswidget.cpp \
    gui/logswidget.cpp \
    gui/mainwindow.cpp \
    gui/statisticswidget.cpp \
    gui/usereditdialog.cpp \
    gui/userswidget.cpp
HEADERS += \
    desktopservice.h \
    rpcservice.h \
    gui/computerswidget.h \
    gui/exportwidget.h \
    gui/groupeditdialog.h \
    gui/groupswidget.h \
    gui/logswidget.h \
    gui/mainwindow.h \
    gui/statisticswidget.h \
    gui/usereditdialog.h \
    gui/userswidget.h
FORMS += \
    gui/computerswidget.ui \
    gui/exportwidget.ui \
    gui/groupeditdialog.ui \
    gui/groupswidget.ui \
    gui/logswidget.ui \
    gui/mainwindow.ui \
    gui/statisticswidget.ui \
    gui/usereditdialog.ui \
    gui/userswidget.ui

RESOURCES += \
    resources.qrc

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
