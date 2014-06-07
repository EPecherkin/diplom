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
