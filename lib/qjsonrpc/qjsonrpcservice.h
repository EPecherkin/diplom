/*
 * Copyright (C) 2012-2013 Matt Broadstone
 * Contact: http://bitbucket.org/devonit/qjsonrpc
 *
 * This file is part of the QJsonRpc Library.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 */
#ifndef QJSONRPCSERVICE_H
#define QJSONRPCSERVICE_H

#include <QVariant>
#include "qjsonrpcmessage.h"

class QJsonRpcSocket;
class QJsonRpcServiceProvider;
class QJsonRpcServicePrivate;
class QJSONRPC_EXPORT QJsonRpcService : public QObject
{
    Q_OBJECT
public:
    explicit QJsonRpcService(QObject *parent = 0);
    ~QJsonRpcService();

Q_SIGNALS:
    void result(const QJsonRpcMessage &result);
    void notifyConnectedClients(const QJsonRpcMessage &message);
    void notifyConnectedClients(const QString &method, const QJsonArray &params = QJsonArray());

protected:
    QJsonRpcSocket *senderSocket();

protected Q_SLOTS:
    bool dispatch(const QJsonRpcMessage &request);

private:
    Q_DISABLE_COPY(QJsonRpcService)
    Q_DECLARE_PRIVATE(QJsonRpcService)
    friend class QJsonRpcServiceProvider;

};

#endif

