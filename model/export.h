#ifndef EXPORT_H
#define EXPORT_H

#include "_model_export.h"
#include <QObject>
#include <QDateTime>
#include "QDjangoModel.h"
#include "user.h"
#include "computer.h"

class MODEL_EXPORT Export : public QDjangoModel {
  Q_OBJECT

  Q_PROPERTY(User* user READ user WRITE user)
  Q_PROPERTY(Computer* computer READ computer WRITE computer)
  Q_PROPERTY(User* exporterUser READ exporterUser WRITE exporterUser)
  Q_PROPERTY(QDateTime dateTime READ dateTime WRITE dateTime)

public:
  explicit Export(QObject* parent = 0);

  User* user() const;
  void user(const User*);

  Computer* computer() const;
  void computer(const Computer*);

  User* exporterUser() const;
  void exporterUser(const User*);

  QDateTime dateTime() const;
  void dateTime(const QDateTime);

private:
  QDateTime _dateTime;

};

#endif // EXPORT_H
