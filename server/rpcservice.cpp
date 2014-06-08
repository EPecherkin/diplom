#include "rpcservice.h"
#include <QTime>
#include <QDjango.h>
#include <QDjangoQuerySet.h>
#include "macros.h"
#include "storage.h"

RpcService::RpcService(QObject* parent) :  QJsonRpcService(parent) {
}

bool RpcService::ping() {
  return true;
}

QString RpcService::getUser(QString login, QString password) {
  QDjangoQuerySet<User> uqs;
  User* user = uqs.get(QDjangoWhere("login", QDjangoWhere::Equals, login)
                       && QDjangoWhere("password", QDjangoWhere::Equals, password));

  if(user == 0)
    return QString();

  return user->toString();
}

QString RpcService::currentTime() {
  FUNCTION
  return QTime::currentTime().toString();
}
