#ifndef GROUP_H
#define GROUP_H

#include <QObject>

class Group : public QObject {
  Q_OBJECT

public:
  explicit Group(QObject* parent = 0);

};

#endif // GROUP_H
