#include <QCoreApplication>
#include <QDebug>
#include "qjsonrpcservice.h"
#include "qjsonrpctcpserver.h"
#include "rpcservice.h"

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  return a.exec();
}

void network() {
  qDebug() << "starting";
  QJsonRpcTcpServer rpcServer;
  qDebug() << "Try to start service";
  rpcServer.addService(new RpcService);
  if (!rpcServer.listen(QHostAddress("localhost"), 30000)) {
    qDebug() << "can't start local server: " << rpcServer.errorString();
    return;
  }
  qDebug() << "service started";
}
