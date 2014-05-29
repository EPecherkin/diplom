#include <QCoreApplication>
#include <QtNetwork/QTcpSocket>
#include <QDebug>
#include "qjsonrpcservice.h"
#include "qjsonrpcsocket.h"
#include "qjsonrpcservicereply.h"
#include "user.h"
#include "keylogger.h"

void logs();
void network();
void model();

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);

  network();

  return a.exec();
}

void logs() {
  qDebug() << "app started";
  qDebug() << "create kl class";
  KeyLogger kl;
  qDebug() << "try to log";
  kl.log();
  qDebug() << "end log";
}

void network() {
  qDebug() << "starting";
  QTcpSocket* socket = new QTcpSocket;
  qDebug() << "Try to connect";
  socket->connectToHost("127.0.0.1", 3023);
  if (!socket->waitForConnected()) {
      qDebug() << "couldn't connect to local server: " << socket->errorString();
      return;
  }
  qDebug() << "connected";
  QEventLoop* loop = new QEventLoop;
  QJsonRpcServiceSocket* service = new QJsonRpcServiceSocket(socket);
  QJsonRpcServiceReply* reply = service->invokeRemoteMethod("rpc_service.currentTime");
  QObject::connect(reply, SIGNAL(finished()), loop, SLOT(quit()));
  loop->exec();
  qDebug() << "response: " << reply->response();
}

void model() {
  qDebug() << "starting";
  User u;
  qDebug() << "started";
}
