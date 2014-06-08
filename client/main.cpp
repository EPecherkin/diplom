#include <QApplication>
#include "desktopservice.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  DesktopService* ds = new DesktopService(&a);
  ds->start();

  return a.exec();
}
