#include "service.h"
#include <QTime>

Service::Service(QObject* parent) :  QJsonRpcService(parent) {
}

QString Service::currentTime() {
  return QTime::currentTime().toString();
}
