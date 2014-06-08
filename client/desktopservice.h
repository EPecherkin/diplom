#ifndef DESKTOPSERVICE_H
#define DESKTOPSERVICE_H

#include <QObject>
#include <QApplication>
#include <QSystemTrayIcon>
#include <QThread>
#include "gui/mainwindow.h"
#include "keylogger.h"
#include "server.h"
#include "storage.h"

class DesktopService : public QObject {
  Q_OBJECT

public:
  static DesktopService* _instance;

  User* currentUser;
  Server* _server;

  explicit DesktopService(QApplication* _application, QObject* parent = 0);

  void start();

private slots:
  void trayIconPressed(QSystemTrayIcon::ActivationReason);
  void trayIconContextQuitPressed();
  void keyPressed(KeyPress* press);

private:
  QApplication* _application;
  QSystemTrayIcon* _icon;
  MainWindow* _mainWindow;
  QThread* _keyLoggerThread;
  KeyLogger* _keyLogger;
  Storage* _storage;

};

#endif // DESKTOPSERVICE_H
