#ifndef COMPUTER_H
#define COMPUTER_H

#include "_model_export.h"
#include <QObject>
#include <QString>
#include <QDateTime>
#include "QDjangoModel.h"
#include "user.h"

class MODEL_EXPORT Computer : public QDjangoModel {
  Q_OBJECT

  Q_PROPERTY(User* user READ user WRITE user)
  Q_PROPERTY(QString ip READ ip WRITE ip)
  Q_PROPERTY(QDateTime lastActivity READ lastActivity WRITE lastActivity)

public:
  explicit Computer(QObject* parent = 0);

  User* user() const;
  void user(const User*);

  QString ip() const;
  void ip(const QString&);

  QDateTime lastActivity() const;
  void lastActivity(const QDateTime&);

private:
  QString _ip;
  QDateTime _lastActivity;

};

#endif // COMPUTER_H
