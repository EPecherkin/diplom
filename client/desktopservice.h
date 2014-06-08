#ifndef DESKTOPSERVICE_H
#define DESKTOPSERVICE_H

#include <QObject>
#include <QApplication>
#include <QSystemTrayIcon>
#include "gui/mainwindow.h"
#include "keylogger.h"
#include "storage.h"

class DesktopService : public QObject {
  Q_OBJECT

public:
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
  KeyLogger* _keyLogger;
  Storage* _storage;

};

#endif // DESKTOPSERVICE_H
