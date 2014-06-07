#include <QApplication>
#include "desktopservice.h"

void model();

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  DesktopService* ds = new DesktopService(&a);
  ds->start();

  return a.exec();
}

#include "user.h"
#include "keypress.h"
#include <QDebug>
#include "QDjango.h"
#include "QDjangoQuerySet.h"
#include <QVariant>
#include <QString>
#include <QStringList>

void model() {
  qDebug() << "model";

  QDjango::setDebugEnabled(true);

  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(":memory:");

  qDebug() << "db";
  if(db.open()) {
    QDjango::setDatabase(db);
    qDebug() << "opened";
  } else {
    qDebug() << "error: " << db.lastError().text();
    return;
  }

  qDebug() << "user";
  if(QDjango::registerModel<User>().createTable()) {
    qDebug() << "created";
  } else {
    qDebug() << "failed";
    return;
  }

  qDebug() << "keypress";
  if(QDjango::registerModel<KeyPress>().createTable()) {
    qDebug() << "created";
  } else {
    qDebug() << "failed";
    return;
  }

  qDebug() << "save user";
  User u;
  u.login("11");
  u.firstName("12");
  u.lastName("22");
  u.middleName("33");
  u.password("334");
  if(u.save()) {
    qDebug() << "success";
  } else {
    qDebug() << "fail";
    return;
  }

  qDebug() << "save keypress";
  KeyPress kp;
  QStringList keys;
  keys.append("1");
  keys.append("2");
  kp.keys(keys);
  kp.start(QDateTime::currentDateTime());
  kp.duration(10);
  kp.user(&u);
  if(kp.save()) {
    qDebug() << "success";
  } else {
    qDebug() << "fail";
    return;
  }

  QDjangoQuerySet<KeyPress> kps;
  KeyPress* nkp = kps.get(QDjangoWhere("pk", QDjangoWhere::Equals, 1));
  QStringList nkeys = nkp->keys();
  nkeys.count();

  qDebug() << "end model";
}
