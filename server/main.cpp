//#include <QCoreApplication>
#include <QApplication>
#include <QDebug>
#include "mainwindow.h"
#include "qjsonrpcservice.h"
#include "qjsonrpctcpserver.h"
#include "rpcservice.h"
#include "user.h"
#include "keypress.h"
#include "QDjango.h"

void gui();
void network();
void model();

int main(int argc, char* argv[]) {
//  QCoreApplication a(argc, argv);
  QApplication a(argc, argv);

  gui();

  return a.exec();
}

void gui() {
  MainWindow* w = new MainWindow;
  w->show();
}

void network() {
  qDebug() << "network";

  QJsonRpcTcpServer* rpcServer = new QJsonRpcTcpServer;
  qDebug() << "Try to start service";
  rpcServer->addService(new RpcService);
  if(!rpcServer->listen(QHostAddress("127.0.0.1"), 3023)) {
    qDebug() << "can't start local server: " << rpcServer->errorString();
    return;
  }

  qDebug() << "end network";
}

void model() {
  qDebug() << "model";

  QDjango::setDebugEnabled(true);

  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(":memory:");

  qDebug() << "db";
  if(db.open()) {
    QDjango::setDatabase(db);
    qDebug() << "opened";
  } else {
    qDebug() << "error: " << db.lastError().text();
    return;
  }

  qDebug() << "user";
  if(QDjango::registerModel<User>().createTable()) {
    qDebug() << "created";
  } else {
    qDebug() << "failed";
    return;
  }

  qDebug() << "keypress";
  if(QDjango::registerModel<KeyPress>().createTable()) {
    qDebug() << "created";
  } else {
    qDebug() << "failed";
    return;
  }

  qDebug() << "end model";
}
