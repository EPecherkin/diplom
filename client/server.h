#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include "user.h"

class Server : public QObject {
  Q_OBJECT

public:
  explicit Server(QString host, qint32 port, QObject* parent = 0);

  bool ping();
  User* getUser(QString login, QString password);

private:
  QString _host;
  qint32 _port;

  QTcpSocket* createTcpSocket();

};

#endif // SERVER_H
