#include "service.h"

Service::Service(QObject* parent) :  QJsonRpcService(parent) {
}

Service::currentTime() {
  return QTime::currentTime().toString();
}
