#include "desktopservice.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include "qjsonrpcservice.h"
#include "gui/mainwindow.h"
#include "rpcservice.h"

DesktopService::DesktopService(QApplication& _application, QObject* parent) : QObject(parent), _application(&_application) {
}

void DesktopService::start() {
  if(!startRpcSerivce()) {
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
  _icon->hide();
  _application->quit();
}

bool DesktopService::startRpcSerivce() {
  _rpcServer = new QJsonRpcTcpServer;
  qDebug() << __FUNCTION__  << "try to start service";
  _rpcServer->addService(new RpcService);
  if(!_rpcServer->listen(QHostAddress("127.0.0.1"), 3023)) {
    qDebug() << __FUNCTION__  << "can't start local service: " << _rpcServer->errorString();
    return false;
  }
  qDebug() << __FUNCTION__  << "service started";
  return true;
}
