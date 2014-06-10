#include "exporter.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

bool Exporter::exportToJson(QList<KeyPress*>& keyPresses, QTextStream& out) {
  QJsonArray jsonArray;
  for(qint32 i = 0; i < keyPresses.size(); ++i) {
    KeyPress* keyPress = keyPresses.at(i);
    QJsonObject object;
    object["computer_id"] = keyPress->computer_id();
    object["application"] = keyPress->application();
    object["start"] = keyPress->start().toString();
    object["duration"] = keyPress->duration();
    object["keys"] = keyPress->keys().join(" ");
    jsonArray.append(QJsonValue(object));
  }

  QJsonDocument jsonDocument;
  jsonDocument.setArray(jsonArray);
  out << jsonDocument.toJson();

  return true;
}

bool Exporter::exportToCSV(QList<KeyPress*>& keyPresses, QTextStream& out) {
  for(qint32 i = 0; i < keyPresses.size(); ++i) {
    KeyPress* keyPress = keyPresses.at(i);
    out
        << keyPress->computer_id() << ';'
        << keyPress->application() << ';'
        << keyPress->start().toString() << ';'
        << keyPress->duration() << ';'
        << keyPress->keys().join(" ") << ';'
        << '\n';
  }

  return true;
}
