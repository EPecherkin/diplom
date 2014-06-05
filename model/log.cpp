#include "log.h"

Log::Log(QObject* parent) : QDjangoModel(parent) {
}

QString Log::table() const {
  return _table;
}

void Log::table(const QString& _table) {
  this->_table = _table;
}

QString Log::operation() const {
  return _operation;
}

void Log::operation(const QString& _operation) {
  this->_operation = _operation;
}

QString Log::changes() const {
  return _changes;
}

void Log::changes(const QString& _changes) {
  this->_changes = _changes;
}
