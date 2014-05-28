#include "rpcservice.h"
#include <QTime>

RpcService::RpcService(QObject* parent) :  QJsonRpcService(parent) {
}

QString RpcService::currentTime() {
  return QTime::currentTime().toString();
}
