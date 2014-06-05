#ifndef GROUP_H
#define GROUP_H

#include "_model_export.h"
#include <QObject>
#include <QString>
#include "QDjangoModel.h"

class MODEL_EXPORT Group : public QDjangoModel {
  Q_OBJECT

  Q_PROPERTY(QString name READ name WRITE name)

public:
  explicit Group(QObject* parent = 0);

  QString name() const;
  void name(const QString&);

private:
  QString _name;

};

#endif // GROUP_H
