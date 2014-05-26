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
#include "qjsonrpcservicereply_p.h"
#include "qjsonrpcservicereply.h"

QJsonRpcServiceReply::QJsonRpcServiceReply(QObject *parent)
    : QObject(*new QJsonRpcServiceReplyPrivate, parent)
{
}

QJsonRpcServiceReply::~QJsonRpcServiceReply()
{
}

QJsonRpcServiceReply::QJsonRpcServiceReply(QJsonRpcServiceReplyPrivate &dd, QObject *parent)
    : QObject(dd, parent)
{
}

QJsonRpcMessage QJsonRpcServiceReply::response() const
{
    Q_D(const QJsonRpcServiceReply);
    return d->response;
}
