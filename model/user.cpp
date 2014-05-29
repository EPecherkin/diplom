#include "user.h"

User::User(QObject* parent) : QDjangoModel(parent) {
}

qint32 User::id() const {
  return _id;
}

void User::id(const qint32& _id) {
  this->_id = _id;
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
