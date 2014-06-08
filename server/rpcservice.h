#ifndef RPCSERVICE_H
#define RPCSERVICE_H

#include <QObject>
#include "qjsonrpcservice.h"

class RpcService : public QJsonRpcService  {
  Q_OBJECT

  Q_CLASSINFO("serviceName", "rpc_service")

public:
  explicit RpcService(QObject* parent = 0);

public slots:
  bool ping();
  QString getUser(QString login, QString password);
  QString currentTime();

};

#endif // RPCSERVICE_H
