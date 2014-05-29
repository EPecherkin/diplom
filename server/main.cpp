#include <QCoreApplication>
#include <QDebug>
#include "qjsonrpcservice.h"
#include "qjsonrpctcpserver.h"
#include "rpcservice.h"
#include "user.h"

void network();
void model();

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  network();

  return a.exec();
}

void network() {
  qDebug() << "starting";
  QJsonRpcTcpServer* rpcServer = new QJsonRpcTcpServer;
  qDebug() << "Try to start service";
  rpcServer->addService(new RpcService);
  if (!rpcServer->listen(QHostAddress("127.0.0.1"), 3023)) {
    qDebug() << "can't start local server: " << rpcServer->errorString();
    return;
  }
  qDebug() << "service started";
}

void model() {
  qDebug() << "starting";
  User u;
  qDebug() << "started";
}
