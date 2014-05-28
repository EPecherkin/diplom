#include <QCoreApplication>
#include <QtNetwork/QTcpSocket>
#include <QDebug>
#include "qjsonrpcservice.h"
#include "qjsonrpcsocket.h"
#include "qjsonrpcservicereply.h"

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  return a.exec();
}

void logs() {
//  qDebug() << "app started";
//  qDebug() << "create kl class";
//  KeyLogger kl;
//  qDebug() << "try to log";
//  kl.log();
//  qDebug() << "end log";
}

int network() {
//  qDebug() << "starting";
//  QTcpSocket socket;
//  qDebug() << "Try to connect";
//  socket.connectToHost("localhost", 3000);
//  if (!socket.waitForConnected()) {
//      qDebug() << "couldn't connect to local server: " << socket.errorString();
//      return -1;
//  }
//  qDebug() << "connected";
//  QEventLoop loop;
//  QJsonRpcServiceSocket service(&socket);
//  QJsonRpcServiceReply *reply = service.invokeRemoteMethod("service.currentTime");
//  QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
//  loop.exec();
//  qDebug() << "response: " << reply->response();
}
