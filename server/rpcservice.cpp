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

bool RpcService::updateUser(QString serializedUser) {
  User* newUser = User::fromString(serializedUser);
  User* user = QDjangoQuerySet<User>().get(QDjangoWhere("id", QDjangoWhere::Equals, newUser->pk()));
  if(user == 0)
    return false;

  user->login(newUser->login());
  user->firstName(newUser->firstName());
  user->lastName(newUser->lastName());
  user->middleName(newUser->middleName());
  if(!newUser->password().isEmpty())
    user->password(newUser->password());

  return user->save();
}
