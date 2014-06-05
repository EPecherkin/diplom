#ifndef DESKTOPSERVICE_H
#define DESKTOPSERVICE_H

#include <QObject>
#include <QApplication>
#include <QSystemTrayIcon>
#include "gui/mainwindow.h"
#include "qjsonrpctcpserver.h"

class DesktopService : public QObject {
  Q_OBJECT

public:
  explicit DesktopService(QApplication& _application, QObject* parent = 0);

  void start();

private slots:
  void trayIconPressed(QSystemTrayIcon::ActivationReason);
  void trayIconContextQuitPressed();

private:
  QApplication* _application;
  QSystemTrayIcon* _icon;
  MainWindow* _mainWindow;
  QJsonRpcTcpServer* _rpcServer;

  bool startRpcSerivce();

};

#endif // DESKTOPSERVICE_H
