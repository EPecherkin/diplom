#include "rpcservice.h"
#include <QTime>
#include "macros.h"

RpcService::RpcService(QObject* parent) :  QJsonRpcService(parent) {
}

bool RpcService::ping() {
  return true;
}

QString RpcService::currentTime() {
  FUNCTION
  return QTime::currentTime().toString();
}
