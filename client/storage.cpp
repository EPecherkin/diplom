#include "storage.h"
#include "macros.h"

bool Storage::init() {
  FUNCTION

  QDjango::setDebugEnabled(true);

  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//  db.setDatabaseName(DB_PATH);
  db.setDatabaseName(":memory:");

  DEBUG << "try to open";
  if(!db.open()) {
    DEBUG << "error: " << db.lastError().text();
    return false;
  }
  QDjango::setDatabase(db);
  DEBUG << "opened";

//  return true;
  return createTables() && addDefaultData() && addTestData();
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

  DEBUG << "No Group group";
  Group ng;
  ng.name("No Group");
  if(!ng.save()) {
    DEBUG << "fail";
    return false;
  }
  DEBUG << "success";

  DEBUG << "No Group normal";
  Normal nn;
  nn.speed(10);
  nn.group(&ng);
  if(!nn.save()) {
    DEBUG << "fail";
    return false;
  }
  DEBUG << "success";

  DEBUG << "Admin user";
  User au;
  au.login("admin");
  au.firstName("First");
  au.lastName("Last");
  au.middleName("Middle");
  au.password("password");
  au.group(&ng);
  if(!au.save()) {
    DEBUG << "fail";
    return false;
  }
  DEBUG << "success";

  return true;
}

bool Storage::addTestData() {
  DEBUG << "Some group";
  Group sg;
  sg.name("Some");
  if(!sg.save()) {
    DEBUG << "fail";
    return false;
  }
  DEBUG << "success";

  DEBUG << "Some normal";
  Normal ns;
  ns.speed(10);
  ns.group(&sg);
  if(!ns.save()) {
    DEBUG << "fail";
    return false;
  }
  DEBUG << "success";

  return true;
}