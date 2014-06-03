#ifndef KEYPRESS_H
#define KEYPRESS_H

#include "model_export.h"
#include <QObject>
#include <QString>
#include <QDateTime>
#include <QStringList>
#include <QByteArray>
#include "QDjangoModel.h"
#include "user.h"

class MODEL_EXPORT KeyPress : public QDjangoModel {
  Q_OBJECT

  Q_PROPERTY(QDateTime start READ start WRITE start)
  Q_PROPERTY(qint64 duration READ duration WRITE duration)
  Q_PROPERTY(QStringList keys READ keys WRITE keys)
  Q_PROPERTY(QByteArray ser_keys READ ser_keys WRITE ser_keys)
  Q_PROPERTY(User* user READ user WRITE user)

  Q_CLASSINFO("keys", "ignore_field=true")

public:
  explicit KeyPress(QObject * parent = 0);

  QDateTime start() const;
  void start(const QDateTime&);

  qint64 duration() const;
  void duration(const qint64&);

  QStringList keys();
  void keys(QStringList&);

  QByteArray ser_keys() const;
  void ser_keys(const QByteArray&);

  User* user() const;
  void user(User*);

private:
  QDateTime _start;
  qint64 _duration;
  QByteArray _ser_keys;

};

#endif // KEYPRESS_H
