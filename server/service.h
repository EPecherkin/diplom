#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>
#include "qjsonrpcservice.h"

class Service : public QJsonRpcService  {
  Q_OBJECT
  Q_CLASSINFO("serviceName", "service")
public:
  explicit Service(QObject* parent = 0);

public Q_SLOTS:
    QString currentTime();

};

#endif // SERVICE_H
