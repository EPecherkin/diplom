#include "keypress.h"

KeyPress::KeyPress(QObject* parent) : QDjangoModel(parent) {
}

QDateTime KeyPress::start() const {
  return _start;
}

void KeyPress::start(const QDateTime& _start) {
  this->_start = _start;
}

QDateTime KeyPress::duration() const {
  return _duration;
}

void KeyPress::duration(const QDateTime& _duration) {
  this->_duration = _duration;
}

QList<QString> KeyPress::keys() const {
  return _keys;
}

void KeyPress::keys(const QList<QString>& _keys) {
  this->_keys = _keys;
}

User* KeyPress::user() const {
  return qobject_cast<User*>(foreignKey("user"));
}

void KeyPress::user(User* user) {
  setForeignKey("user", user);
}
