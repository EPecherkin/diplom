#include <QCoreApplication>
#include <QDebug>
#include "qjsonrpcservice.h"
#include "qjsonrpctcpserver.h"
#include "service.h"

void network();

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  qDebug() << "starting";
  QJsonRpcTcpServer rpcServer;
  qDebug() << "Try to start service";
  rpcServer.addService(new Service);
  if (!rpcServer.listen(QHostAddress("127.0.0.1"), 3000)) {
    qDebug() << "can't start local server: " << rpcServer.errorString();
    return -1;
  }
  qDebug() << "service started";

  return a.exec();
}

void network() {
  qDebug() << "starting";
  QJsonRpcTcpServer rpcServer;
  qDebug() << "Try to start service";
  rpcServer.addService(new Service);
  if (!rpcServer.listen(QHostAddress("localhost"), 30000)) {
    qDebug() << "can't start local server: " << rpcServer.errorString();
    return;
  }
  qDebug() << "service started";
}
