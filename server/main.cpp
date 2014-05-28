#include <QCoreApplication>
#include <QDebug>
#include "qjsonrpcservice.h"
#include "qjsonrpctcpserver.h"
#include "rpcservice.h"

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  qDebug() << "starting";
  QJsonRpcTcpServer rpcServer;
  qDebug() << "Try to start service";
  rpcServer.addService(new RpcService);
  if (!rpcServer.listen(QHostAddress("localhost"), 3000)) {
    qDebug() << "can't start local server: " << rpcServer.errorString();
    return -1;
  }
  qDebug() << "service started";

  return a.exec();
}

int network() {
  qDebug() << "starting";
  QJsonRpcTcpServer rpcServer;
  qDebug() << "Try to start service";
  rpcServer.addService(new RpcService);
  if (!rpcServer.listen(QHostAddress("localhost"), 30000)) {
    qDebug() << "can't start local server: " << rpcServer.errorString();
    return -1;
  }
  qDebug() << "service started";
}
