#include <QApplication>
#include "desktopservice.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  DesktopService* ds = new DesktopService(&a);
  ds->start();

  return a.exec();
}

//void network() {
//  qDebug() << "starting";
//  QTcpSocket* socket = new QTcpSocket;
//  qDebug() << "Try to connect";
//  socket->connectToHost("127.0.0.1", 3023);
//  if(!socket->waitForConnected()) {
//      qDebug() << "couldn't connect to local server: " << socket->errorString();
//      return;
//  }
//  qDebug() << "connected";
//  QEventLoop* loop = new QEventLoop;
//  QJsonRpcServiceSocket* service = new QJsonRpcServiceSocket(socket);
//  QJsonRpcServiceReply* reply = service->invokeRemoteMethod("rpc_service.currentTime");
//  QObject::connect(reply, SIGNAL(finished()), loop, SLOT(quit()));
//  loop->exec();
//  qDebug() << "response: " << reply->response();
//}
