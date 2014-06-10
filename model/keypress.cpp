#include "keypress.h"

KeyPress::KeyPress(QObject* parent) : QDjangoModel(parent), _application(""), _start(QDateTime::currentDateTime()), _duration(1) {
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

qint32 KeyPress::user_id() const {
  return _user_id;
}

void KeyPress::user_id(const qint32& _user_id) {
  this->_user_id = _user_id;
}

qint32 KeyPress::computer_id() const {
  return _computer_id;
}

void KeyPress::computer_id(const qint32& _computer_id) {
  this->_computer_id = _computer_id;
}

QString KeyPress::toString() const {
  QByteArray ba;
  QDataStream ds(&ba, QIODevice::WriteOnly);
  ds << pk() << _user_id << _computer_id << _application << _start << _duration << _ser_keys;
  return QString::fromUtf8(ba.toBase64());
}

KeyPress* KeyPress::fromString(const QString& string) {
  KeyPress* keyPress = new KeyPress;

  QByteArray ba = QByteArray::fromBase64(string.toUtf8());
  QDataStream ds(&ba, QIODevice::ReadOnly);

  QVariant pk;
  ds >> pk >> keyPress->_user_id >> keyPress->_computer_id >> keyPress->_application >> keyPress->_start >> keyPress->_duration >> keyPress->_ser_keys;
  keyPress->setPk(pk);

  return keyPress;
}
