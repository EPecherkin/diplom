#include "desktopservice.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include "qjsonrpcservice.h"
#include "macros.h"
#include "gui/logindialog.h"
#include "gui/mainwindow.h"
#include "storage.h"

DesktopService* DesktopService::_instance = 0;

DesktopService::DesktopService(QApplication* _application, QObject* parent) : QObject(parent), _application(_application), _keyLoggerThread(new QThread), _keyLogger(new KeyLogger), _storage(new Storage) {
  DesktopService::_instance = this;
  _keyLogger->moveToThread(_keyLoggerThread);
  connect(_keyLoggerThread, SIGNAL(started()), _keyLogger, SLOT(startLog()), Qt::DirectConnection);
}

void DesktopService::start() {
  FUNCTION

  if(!_storage->init()) {
    _application->quit();
    return;
  }

  LoginDialog* ld = new LoginDialog;
  if(ld->exec() != QDialog::Accepted) {
    _application->quit();
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

  connect(_keyLogger, SIGNAL(keyPressed(KeyPress*)), this, SLOT(keyPressed(KeyPress*)), Qt::QueuedConnection);
  _keyLoggerThread->start();

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
  keyPress->user(DesktopService::currentUser);
  keyPress->save();
}
