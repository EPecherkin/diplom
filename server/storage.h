#ifndef STORAGE_H
#define STORAGE_H

#include <QObject>
#include "QDjango.h"
#include "QDjangoQuerySet.h"
#include "computer.h"
#include "export.h"
#include "group.h"
#include "keypress.h"
#include "log.h"
#include "normal.h"
#include "user.h"

class Storage : public QObject {
  Q_OBJECT

public:
  bool init();

private:
  bool createTables();
  bool addDefaultData();
  bool addTestData();

};

#endif // STORAGE_H
