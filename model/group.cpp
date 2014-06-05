#include "group.h"

Group::Group(QObject* parent) : QDjangoModel(parent) {
}

QString Group::name() const {
  return _name;
}

void Group::name(const QString& _name) {
  this->_name = _name;
}
