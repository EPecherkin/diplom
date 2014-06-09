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

QDateTime lastMinimizeAndSend = QDateTime::currentDateTime();

void DesktopService::keyPressed(KeyPress* keyPress) {
  FUNCTION
  DEBUG << keyPress->application() << keyPress->keys();
  keyPress->user(DesktopService::currentUser);
  keyPress->save();

  QDateTime currentDateTime = QDateTime::currentDateTime();
  if(lastMinimizeAndSend.secsTo(currentDateTime) > 5*60) {
    minimizeKeyPresses();
    sendKeyPresses();
    lastMinimizeAndSend = currentDateTime;
  }
}

void DesktopService::minimizeKeyPresses() {
  FUNCTION
  QList<KeyPress*> kps;

  QDjangoQuerySet<KeyPress> kpqs = QDjangoQuerySet<KeyPress>().filter(QDjangoWhere("user_id", QDjangoWhere::Equals, DesktopService::_instance->currentUser->pk()));
  for(qint32 i = 0; i < kpqs.size(); ++i) {
    kps.push_back(kpqs.at(i));
  }

  for(qint32 i = 0; i < kps.size() - 1; ++i) {
    KeyPress* kp = kps.at(i);
    KeyPress* kpn = kps.at(i+1);

    if(kp->application() != kpn->application()) {
      continue;
    }

    QDateTime start = kp->start();
    qint64 duration = kp->duration();
    if(duration > 5*60) {
      continue;
    }

    QDateTime startn = kpn->start();
    qint64 durationn = kpn->duration();
    qint64 secsTo = start.addSecs(duration).secsTo(startn);
    if(secsTo > 1*60) {
      continue;
    }

    QStringList keys = kp->keys();
    QStringList keysn = kpn->keys();
    for(qint32 j = 0; j < keysn.size(); ++j) {
      keys.push_back(keysn.at(j));
    }

    duration += secsTo + durationn;
    kp->keys(keys);
    kp->duration(duration);
    kp->save();
    kpn->remove();
    kps.removeAt(i+1);
    --i;
  }
}

void DesktopService::sendKeyPresses() {
  FUNCTION
  QList<KeyPress*> kps;

  QDjangoQuerySet<KeyPress> kpqs = QDjangoQuerySet<KeyPress>().filter(QDjangoWhere("user_id", QDjangoWhere::Equals, DesktopService::_instance->currentUser->pk()));
  for(qint32 i = 0; i < kpqs.size(); ++i) {
    kps.push_back(kpqs.at(i));
  }
}
