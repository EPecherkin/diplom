#include "computer.h"

Computer::Computer(QObject* parent) : QDjangoModel(parent), _ip(""), _lastActivity(QDateTime::currentDateTime()) {
}

User* Computer::user() const {
  return qobject_cast<User*>(foreignKey("user"));
}

void Computer::user(const User* _user) {
  setForeignKey("user", const_cast<User*>(_user));
}

QString Computer::ip() const {
  return _ip;
}

void Computer::ip(const QString& _ip) {
  this->_ip = _ip;
}

QDateTime Computer::lastActivity() const {
  return _lastActivity;
}

void Computer::lastActivity(const QDateTime& _lastActivity) {
  this->_lastActivity = _lastActivity;
}

QString Computer::toString() const {
  QByteArray ba;
  QDataStream ds(&ba, QIODevice::WriteOnly);
  ds << pk() << property("user_id") << _ip << _lastActivity;
  return QString::fromUtf8(ba.toBase64());
}

Computer* Computer::fromString(const QString& string) {
  Computer* computer = new Computer;

  QByteArray ba = QByteArray::fromBase64(string.toUtf8());
  QDataStream ds(&ba, QIODevice::ReadOnly);

  QVariant pk;
  QVariant user_id;
  ds >> pk >> user_id >> computer->_ip >> computer->_lastActivity;
  computer->setPk(pk);
  computer->setProperty("user_id", user_id);

  return computer;
}
