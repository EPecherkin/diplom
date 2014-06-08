#include "desktopservice.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include "qjsonrpcservice.h"
#include "macros.h"
#include "gui/mainwindow.h"
#include "storage.h"

DesktopService::DesktopService(QApplication* _application, QObject* parent) : QObject(parent), _application(_application), _keyLogger(new KeyLogger), _storage(new Storage) {
  connect(_keyLogger, SIGNAL(keyPressed(KeyPress*)), this, SLOT(keyPressed(KeyPress*)));
}

void DesktopService::start() {
  FUNCTION
  _keyLogger->startLog();

  if(!_storage->init()) {
    trayIconContextQuitPressed();
    return;
  }

  _application->setQuitOnLastWindowClosed(false);

  _icon = new QSystemTrayIcon(QIcon(":/icon.png"), this);

  QMenu* menu = new QMenu;

  QAction* quitAction = new QAction("quit", menu);

  menu->addAction(quitAction);

  _icon->setContextMenu(menu);
  _icon->show();

  connect(quitAction, SIGNAL(triggered()), this, SLOT(trayIconContextQuitPressed()));
  connect(_icon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayIconPressed(QSystemTrayIcon::ActivationReason)));

  _mainWindow = new MainWindow;
  _mainWindow->show();
}

void DesktopService::trayIconPressed(QSystemTrayIcon::ActivationReason _activationReason) {
  FUNCTION
  switch (_activationReason) {
  case QSystemTrayIcon::DoubleClick:
    _mainWindow->show();
    _mainWindow->showNormal();
    _mainWindow->activateWindow();
    break;
  default:
    break;
  }
}

void DesktopService::trayIconContextQuitPressed() {
  FUNCTION
  _icon->hide();
  _application->quit();
}

void DesktopService::keyPressed(KeyPress* keyPress) {
  DEBUG << keyPress->application() << keyPress->keys();
}
