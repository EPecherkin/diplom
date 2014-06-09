#ifndef KEYPRESS_H
#define KEYPRESS_H

#include "_model_export.h"
#include <QObject>
#include <QString>
#include <QDateTime>
#include <QStringList>
#include <QByteArray>
#include "QDjangoModel.h"
#include "serializablemodel.h"
#include "user.h"
#include "computer.h"

class MODEL_EXPORT KeyPress : public QDjangoModel, public SerializableModel {
  Q_OBJECT

  Q_PROPERTY(User* user READ user WRITE user)
  Q_PROPERTY(Computer* computer READ computer WRITE computer)
  Q_PROPERTY(QString application READ application WRITE application)
  Q_PROPERTY(QDateTime start READ start WRITE start)
  Q_PROPERTY(qint64 duration READ duration WRITE duration)
  Q_PROPERTY(QStringList keys READ keys WRITE keys)
  Q_PROPERTY(QByteArray ser_keys READ ser_keys WRITE ser_keys)

  Q_CLASSINFO("keys", "ignore_field=true")

public:
  explicit KeyPress(QObject * parent = 0);

  User* user() const;
  void user(const User*);

  Computer* computer() const;
  void computer(const Computer*);

  QString application() const;
  void application(const QString&);

  QDateTime start() const;
  void start(const QDateTime&);

  qint64 duration() const;
  void duration(const qint64&);

  QStringList keys() const;
  void keys(const QStringList&);

  QByteArray ser_keys() const;
  void ser_keys(const QByteArray&);

  virtual QString toString() const;
  static KeyPress* fromString(const QString&);

private:
  QString _application;
  QDateTime _start;
  qint64 _duration;
  QByteArray _ser_keys;

};

#endif // KEYPRESS_H
