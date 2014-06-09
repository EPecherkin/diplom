#ifndef LOG_H
#define LOG_H

#include "_model_export.h"
#include <QObject>
#include <QString>
#include "QDjangoModel.h"

class MODEL_EXPORT Log : public QDjangoModel {
  Q_OBJECT

  Q_PROPERTY(QString table READ table WRITE table)
  Q_PROPERTY(QString action READ action WRITE action)
  Q_PROPERTY(QString changes READ changes WRITE changes)

public:
  explicit Log(QObject* parent = 0);

  QString table() const;
  void table(const QString&);

  QString action() const;
  void action(const QString&);

  QString changes() const;
  void changes(const QString&);

private:
  QString _table;
  QString _action;
  QString _changes;

};

#endif // LOG_H
