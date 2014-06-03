#ifndef COMPUTER_H
#define COMPUTER_H

#include <QObject>

class Computer : public QObject {
  Q_OBJECT

public:
  explicit Computer(QObject* parent = 0);

};

#endif // COMPUTER_H
