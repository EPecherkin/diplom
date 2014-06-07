#include "normal.h"

Normal::Normal(QObject* parent) : QDjangoModel(parent), _speed(0) {
}

Group* Normal::group() const {
  return qobject_cast<Group*>(foreignKey("group"));
}

void Normal::group(const Group* _group) {
  setForeignKey("group", const_cast<Group*>(_group));
}

qint32 Normal::speed() const {
  return _speed;
}

void Normal::speed(const qint32& _speed) {
  this->_speed = _speed;
}
