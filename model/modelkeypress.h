#ifndef MODELKEYPRESS_H
#define MODELKEYPRESS_H

#include "model_export.h"
#include <QObject>
#include <QString>
#include <QDateTime>
#include <QList>

class MODEL_EXPORT ModelKeyPress : public QObject {
  Q_OBJECT

  Q_PROPERTY(QDateTime start MEMBER start)
  Q_PROPERTY(QDateTime duration MEMBER duration)
  Q_PROPERTY(QList<QString> keys MEMBER keys)
  Q_PROPERTY(qint32 user_id MEMBER user_id)

public:
  explicit ModelKeyPress(QObject * parent = 0);

private:
  QDateTime start;
  QDateTime duration;
  QList<QString> keys;
  qint32 user_id;

};

#endif // MODELKEYPRESS_H
