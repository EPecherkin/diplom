#include "user.h"

User::User(QObject* parent) : QDjangoModel(parent), _externalUserID(0), _login(""), _firstName(""), _lastName(""), _middleName(""), _password("") {
}

qint32 User::externalUserID() const {
  return _externalUserID;
}

void User::externalUserID(const qint32& _externalUserID) {
  this->_externalUserID = _externalUserID;
}

Group* User::group() const {
  return qobject_cast<Group*>(foreignKey("group"));
}

void User::group(const Group* _group) {
  setForeignKey("group", const_cast<Group*>(_group));
}

QString User::login() const {
  return _login;
}

void User::login(const QString& _login) {
  this->_login = _login;
}

QString User::firstName() const {
  return _firstName;
}

void User::firstName(const QString& _firstName) {
  this->_firstName = _firstName;
}

QString User::lastName() const {
  return _lastName;
}

void User::lastName(const QString& _lastName) {
  this->_lastName = _lastName;
}

QString User::middleName() const {
  return _middleName;
}

void User::middleName(const QString& _middleName) {
  this->_middleName = _middleName;
}

QString User::password() const {
  return _password;
}

void User::password(const QString& _password) {
  this->_password = _password;
}

QString User::toString() const {
  QByteArray ba;
  QDataStream ds(&ba, QIODevice::WriteOnly);
  ds << pk() << _login << _firstName << _lastName << _middleName << _password;
  return QString::fromUtf8(ba.toBase64());
}

User* User::fromString(const QString& string) {
  User* user = new User;

  QByteArray ba = QByteArray::fromBase64(string.toUtf8());
  QDataStream ds(&ba, QIODevice::ReadOnly);

  QVariant pk;
  ds >> pk >> user->_login >> user->_firstName >> user->_lastName >> user->_middleName >> user->_password;
  user->setPk(pk);

  return user;
}
