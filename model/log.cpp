#include "log.h"

Log::Log(QObject* parent) : QDjangoModel(parent), _table(""), _action(""), _changes("") {
}

QString Log::table() const {
  return _table;
}

void Log::table(const QString& _table) {
  this->_table = _table;
}

QString Log::action() const {
  return _action;
}

void Log::action(const QString& _action) {
  this->_action = _action;
}

QString Log::changes() const {
  return _changes;
}

void Log::changes(const QString& _changes) {
  this->_changes = _changes;
}
