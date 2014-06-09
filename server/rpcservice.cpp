#include "rpcservice.h"
#include <QTime>
#include <QDjango.h>
#include <QDjangoQuerySet.h>
#include "macros.h"
#include "storage.h"

RpcService::RpcService(QObject* parent) :  QJsonRpcService(parent) {
}

bool RpcService::ping() {
  FUNCTION
  return true;
}

QString RpcService::getUser(QString login, QString password) {
  FUNCTION
  QDjangoQuerySet<User> uqs;
  User* user = uqs.get(QDjangoWhere("login", QDjangoWhere::Equals, login)
                       && QDjangoWhere("password", QDjangoWhere::Equals, password));

  if(user == 0)
    return QString();

  return user->toString();
}

bool RpcService::updateUser(QString serializedUser) {
  FUNCTION
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

QString RpcService::getComputer(QString serializedUser) {
  FUNCTION
  Computer* computer = QDjangoQuerySet<Computer>().get(QDjangoWhere("id", QDjangoWhere::Equals, 1));
  return computer->toString();
}

bool RpcService::addKeyPress(QString serializedKeyPress) {
  FUNCTION
  KeyPress* keyPress = KeyPress::fromString(serializedKeyPress);
  return keyPress->save();
}

QString RpcService::getKeyPresses(QString serializedUser) {
  FUNCTION
  User* user = User::fromString(serializedUser);
  QDjangoQuerySet<KeyPress> kpqs = QDjangoQuerySet<KeyPress>().filter(QDjangoWhere("user_id", QDjangoWhere::Equals, user->pk()));
  QStringList serializedKeyPresses;
  for(qint32 i = 0; i < kpqs.size(); ++i) {
    KeyPress* keyPress = kpqs.at(i);
    serializedKeyPresses.push_back(keyPress->toString());
  }
  QByteArray serialized;
  QDataStream in(&serialized, QIODevice::WriteOnly);
  in << serializedKeyPresses;
  QString result = QString::fromUtf8(serialized.toBase64());
  return result;
}
