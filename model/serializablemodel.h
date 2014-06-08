#ifndef SERIALIZABLEMODEL_H
#define SERIALIZABLEMODEL_H

#include "_model_export.h"
#include <QString>

class MODEL_EXPORT SerializableModel {
public:
  virtual QString toString() const = 0;
  //static Model* fromString(QString&);
};

#endif // SERIALIZABLEMODEL_H
