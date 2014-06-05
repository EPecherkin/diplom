#ifndef NORMAL_H
#define NORMAL_H

#include "_model_export.h"
#include <QObject>
#include "QDjangoModel.h"
#include "group.h"

class MODEL_EXPORT Normal : public QDjangoModel {
  Q_OBJECT

  Q_PROPERTY(Group* group READ group WRITE group)
  Q_PROPERTY(qint32 speed READ speed WRITE speed)

public:
  explicit Normal(QObject* parent = 0);

  Group* group() const;
  void group(const Group*);

  qint32 speed() const;
  void speed(const qint32&);

private:
  qint32 _speed;

};

#endif // NORMAL_H
