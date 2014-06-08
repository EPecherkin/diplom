#ifndef KEYLOGGER_H
#define KEYLOGGER_H

#include <QObject>
#include <keypress.h>

class KeyLogger : public QObject {
  Q_OBJECT

public:
  explicit KeyLogger(QObject* parent = 0);

public slots:
  void startLog();

signals:
  void keyPressed(KeyPress* press);

};

#endif // KEYLOGGER_H
