#ifndef EXPORTER_H
#define EXPORTER_H

#include <QList>
#include <QTextStream>
#include "keypress.h"

class Exporter {
public:
  static bool exportToJson(QList<KeyPress*>& keyPresses, QTextStream& out);
  static bool exportToCSV(QList<KeyPress*>& keyPresses, QTextStream& out);
};

#endif // EXPORTER_H
