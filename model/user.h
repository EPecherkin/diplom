#ifndef USER_H
#define USER_H

#include "_model_export.h"
#include <QObject>
#include <QString>
#include "QDjangoModel.h"
#include "serializablemodel.h"
#include "group.h"

class MODEL_EXPORT User : public QDjangoModel, public SerializableModel {
  Q_OBJECT

  Q_PROPERTY(qint32 externalUserID READ externalUserID WRITE externalUserID)
  Q_PROPERTY(Group* group READ group WRITE group)
  Q_PROPERTY(QString login READ login WRITE login)
  Q_PROPERTY(QString firstName READ firstName WRITE firstName)
  Q_PROPERTY(QString lastName READ lastName WRITE lastName)
  Q_PROPERTY(QString middleName READ middleName WRITE middleName)
  Q_PROPERTY(QString password READ password WRITE password)

public:
  explicit User(QObject * parent = 0);

  qint32 externalUserID() const;
  void externalUserID(const qint32&);

  Group* group() const;
  void group(const Group*);

  QString login() const;
  void login(const QString&);

  QString firstName() const;
  void firstName(const QString&);

  QString lastName() const;
  void lastName(const QString&);

  QString middleName() const;
  void middleName(const QString&);

  QString password() const;
  void password(const QString&);

  virtual QString toString() const;
  static User* fromString(const QString&);

private:
  qint32 _externalUserID;
  QString _login;
  QString _firstName;
  QString _lastName;
  QString _middleName;
  QString _password;

};

#endif // USER_H
