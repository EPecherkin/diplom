#include "rpcservice.h"
#include <QTime>
#include <QDebug>

RpcService::RpcService(QObject* parent) :  QJsonRpcService(parent) {
}

QString RpcService::currentTime() {
  return QTime::currentTime().toString();
}
