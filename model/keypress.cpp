#include "keypress.h"

KeyPress::KeyPress(QObject* parent) : QDjangoModel(parent) {
}

QDateTime KeyPress::start() const {
  return _start;
}

void KeyPress::start(const QDateTime& _start) {
  this->_start = _start;
}

qint64 KeyPress::duration() const {
  return _duration;
}

void KeyPress::duration(const qint64& _duration) {
  this->_duration = _duration;
}

QStringList KeyPress::keys() {
  QStringList result;
  QDataStream in(&_ser_keys, QIODevice::ReadOnly);
  in >> result;
  return result;
}

void KeyPress::keys(QStringList& _keys) {
  QDataStream out(&_ser_keys, QIODevice::WriteOnly);
  out << _keys;
}

QByteArray KeyPress::ser_keys() const {
  return _ser_keys;
}

void KeyPress::ser_keys(const QByteArray& _ser_keys) {
  this->_ser_keys = _ser_keys;
}

User* KeyPress::user() const {
  return qobject_cast<User*>(foreignKey("user"));
}

void KeyPress::user(User* user) {
  setForeignKey("user", user);
}
