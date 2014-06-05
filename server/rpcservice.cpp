#include "rpcservice.h"
#include <QTime>
#include "macros.h"

RpcService::RpcService(QObject* parent) :  QJsonRpcService(parent) {
}

QString RpcService::currentTime() {
  FUNCTION
  return QTime::currentTime().toString();
}
