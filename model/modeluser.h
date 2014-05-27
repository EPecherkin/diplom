#ifndef MODELUSER_H
#define MODELUSER_H

#include "model_export.h"
#include <QObject>
#include <QString>

class MODEL_EXPORT ModelUser : public QObject {
  Q_OBJECT

  Q_PROPERTY(qint32 id MEMBER id)
  Q_PROPERTY(QString login MEMBER login)
  Q_PROPERTY(QString firstName MEMBER firstName)
  Q_PROPERTY(QString lastName MEMBER lastName)
  Q_PROPERTY(QString middleName MEMBER middleName)
  Q_PROPERTY(QString password MEMBER password)

public:
  explicit ModelUser(QObject * parent = 0);

private:
  qint32 id;
  QString login;
  QString firstName;
  QString lastName;
  QString middleName;
  QString password;

};

#endif // MODELUSER_H
