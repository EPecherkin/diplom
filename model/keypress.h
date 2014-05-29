#ifndef KEYPRESS_H
#define KEYPRESS_H

#include "model_export.h"
#include <QObject>
#include <QString>
#include <QDateTime>
#include <QList>
#include "QDjangoModel.h"
#include "user.h"

class MODEL_EXPORT KeyPress : public QDjangoModel {
  Q_OBJECT

  Q_PROPERTY(QDateTime start READ start WRITE start)
  Q_PROPERTY(QDateTime duration READ duration WRITE duration)
  Q_PROPERTY(QList<QString> keys READ keys WRITE keys)
  Q_PROPERTY(User* user READ user WRITE user)

public:
  explicit KeyPress(QObject * parent = 0);

  QDateTime start() const;
  void start(const QDateTime&);

  QDateTime duration() const;
  void duration(const QDateTime&);

  QList<QString> keys() const;
  void keys(const QList<QString>&);

  User* user() const;
  void user(User*);

private:
  QDateTime _start;
  QDateTime _duration;
  QList<QString> _keys;

};

#endif // KEYPRESS_H
