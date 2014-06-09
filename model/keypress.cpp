#include "keypress.h"

KeyPress::KeyPress(QObject* parent) : QDjangoModel(parent), _application(""), _start(QDateTime::currentDateTime()), _duration(0) {
  keys(QStringList());
}

User* KeyPress::user() const {
  return qobject_cast<User*>(foreignKey("user"));
}

void KeyPress::user(const User* _user) {
  setForeignKey("user", const_cast<User*>(_user));
}

Computer* KeyPress::computer() const {
  return qobject_cast<Computer*>(foreignKey("computer"));
}

void KeyPress::computer(const Computer* _computer) {
  setForeignKey("computer", const_cast<Computer*>(_computer));
}

QString KeyPress::application() const {
  return _application;
}

void KeyPress::application(const QString& _application) {
  this->_application = _application;
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

QStringList KeyPress::keys() const {
  QStringList result;
  QDataStream in(const_cast<QByteArray*>(&_ser_keys), QIODevice::ReadOnly);
  in >> result;
  return result;
}

void KeyPress::keys(const QStringList& _keys) {
  QDataStream out(&_ser_keys, QIODevice::WriteOnly);
  out << _keys;
}

QByteArray KeyPress::ser_keys() const {
  return _ser_keys;
}

void KeyPress::ser_keys(const QByteArray& _ser_keys) {
  this->_ser_keys = _ser_keys;
}

QString KeyPress::toString() const {
  QByteArray ba;
  QDataStream ds(&ba, QIODevice::WriteOnly);
  ds << pk() << property("user_id") << property("computer_id") << _application << _start << _duration << _ser_keys;
  return QString::fromUtf8(ba.toBase64());
}

KeyPress* KeyPress::fromString(const QString& string) {
  KeyPress* keyPress = new KeyPress;

  QByteArray ba = QByteArray::fromBase64(string.toUtf8());
  QDataStream ds(&ba, QIODevice::ReadOnly);

  QVariant pk;
  QVariant user_id;
  QVariant computer_id;
  ds >> pk >> user_id >> computer_id >> keyPress->_application >> keyPress->_start >> keyPress->_duration >> keyPress->_ser_keys;
  keyPress->setPk(pk);
  keyPress->setProperty("user_id", user_id);
  keyPress->setProperty("computer_id", computer_id);

  return keyPress;
}
