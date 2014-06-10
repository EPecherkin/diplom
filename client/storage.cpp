#include "storage.h"
#include "macros.h"

bool Storage::init() {
  FUNCTION

  QDjango::setDebugEnabled(true);

  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(DB_PATH);

  DEBUG << "try to open";
  if(!db.open()) {
    DEBUG << "error: " << db.lastError().text();
    return false;
  }
  QDjango::setDatabase(db);
  DEBUG << "opened";

  return DB_INIT_RETURN;
}

template<class C> bool createTable() {
  DEBUG << typeid(C).name();
  if(!QDjango::registerModel<C>().createTable()) {
    DEBUG << "failed";
    return false;
  }
  DEBUG << "created";
  return true;
}

bool Storage::createTables() {
  FUNCTION

  if(!createTable<Group>())
    return false;

  if(!createTable<Normal>())
    return false;

  if(!createTable<User>())
    return false;

  if(!createTable<Computer>())
    return false;

  if(!createTable<KeyPress>())
    return false;

  if(!createTable<Export>())
    return false;

  if(!createTable<Log>())
    return false;

  return true;
}

bool Storage::addDefaultData() {
  FUNCTION
  return true;
}

bool Storage::addTestData() {
  FUNCTION
  return true;
}
