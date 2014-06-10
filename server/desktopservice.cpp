#include "desktopservice.h"
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include "qjsonrpcservice.h"
#include "macros.h"
#include "gui/mainwindow.h"
#include "rpcservice.h"
#include "storage.h"

DesktopService::DesktopService(QApplication* _application, QObject* parent) : QObject(parent), _application(_application), _rpcServer(new QJsonRpcTcpServer), _storage(new Storage) {
}

void MyMessageOutput(QtMsgType Type, const QMessageLogContext& Context, const QString& Message);

void DesktopService::start() {
  FUNCTION
  if(!_storage->init() || !startRpcServer()) {
    _application->quit();
    return;
  }

  qInstallMessageHandler(MyMessageOutput);

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

bool DesktopService::startRpcServer() {
  FUNCTION
  DEBUG << "try to start";
  _rpcServer->addService(new RpcService);
  if(!_rpcServer->listen(QHostAddress("127.0.0.1"), 3023)) {
    DEBUG << "error: " << _rpcServer->errorString();
    return false;
  }
  DEBUG << "started";
  return true;
}

void MyMessageOutput(QtMsgType Type, const QMessageLogContext& Context, const QString& Message) {
  Log* log = new Log;
  log->table(Message.split(";").at(0));
  log->action(Message.split(";").at(1));
  log->changes(Message.split(";").at(2));
  log->save();
}
