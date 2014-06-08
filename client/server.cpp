#include "server.h"
#include <QEventLoop>
#include "qjsonrpcsocket.h"
#include "qjsonrpcservicereply.h"
#include "macros.h"

Server::Server(QString host, qint32 port, QObject* parent) : QObject(parent), _host(host), _port(port) {
}

bool Server::ping() {
  FUNCTION
  QTcpSocket* tcpSocket = createTcpSocket();
  if(tcpSocket == 0)
    return false;

  QEventLoop* loop = new QEventLoop;
  QJsonRpcServiceSocket* service = new QJsonRpcServiceSocket(tcpSocket);
  QJsonRpcServiceReply* reply = service->invokeRemoteMethod("rpc_service.ping");
  QObject::connect(reply, SIGNAL(finished()), loop, SLOT(quit()));
  loop->exec();
  DEBUG << "response: " << reply->response();
  bool result = reply->response().result().toBool();
  tcpSocket->close();
  return result;
}

User* Server::getUser(QString login, QString password) {
  QTcpSocket* tcpSocket = createTcpSocket();
  if(tcpSocket == 0)
    return 0;

  QEventLoop* loop = new QEventLoop;
  QJsonRpcServiceSocket* service = new QJsonRpcServiceSocket(tcpSocket);
  QJsonRpcServiceReply* reply = service->invokeRemoteMethod("rpc_service.getUser", login, password);
  QObject::connect(reply, SIGNAL(finished()), loop, SLOT(quit()));
  loop->exec();
  DEBUG << "response: " << reply->response();
  QString result = reply->response().result().toString();
  if(result.isEmpty()) {
    return 0;
  }
  User* user = User::fromString(result);
  tcpSocket->close();
  return user;
}

bool Server::updateUser(User* user) {
  QTcpSocket* tcpSocket = createTcpSocket();
  if(tcpSocket == 0)
    return 0;

  QEventLoop* loop = new QEventLoop;
  QJsonRpcServiceSocket* service = new QJsonRpcServiceSocket(tcpSocket);
  QJsonRpcServiceReply* reply = service->invokeRemoteMethod("rpc_service.updateUser", user->toString());
  QObject::connect(reply, SIGNAL(finished()), loop, SLOT(quit()));
  loop->exec();
  DEBUG << "response: " << reply->response();
  bool result = reply->response().result().toBool();
  tcpSocket->close();
  return result;
}

QTcpSocket* Server::createTcpSocket() {
  QTcpSocket* socket = new QTcpSocket;
  DEBUG << "connecting";
  socket->connectToHost(_host, _port);
  if(!socket->waitForConnected()) {
    DEBUG << "couldn't connect" << socket->errorString();
    return 0;
  }
  DEBUG << "connected";
  return socket;
}
