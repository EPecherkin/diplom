#include "export.h"

Export::Export(QObject* parent) : QDjangoModel(parent) {
}

User* Export::user() const {
  return qobject_cast<User*>(foreignKey("user"));
}

void Export::user(const User* _user) {
  setForeignKey("user", const_cast<User*>(_user));
}

Computer* Export::computer() const {
  return qobject_cast<Computer*>(foreignKey("computer"));
}

void Export::computer(const Computer* _computer) {
  setForeignKey("computer", const_cast<Computer*>(_computer));
}

User* Export::exporterUser() const {
  return qobject_cast<User*>(foreignKey("exporterUser"));
}

void Export::exporterUser(const User* _exporterUser) {
  setForeignKey("exporterUser", const_cast<User*>(_exporterUser));
}

QDateTime Export::dateTime() const {
  return _dateTime;
}

void Export::dateTime(const QDateTime) {
  this->_dateTime = _dateTime;
}
