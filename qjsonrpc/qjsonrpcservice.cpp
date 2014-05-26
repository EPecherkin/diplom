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
#include <QVarLengthArray>
#include <QMetaMethod>
#include <QEventLoop>
#include <QDebug>

#include "qjsonrpcsocket.h"
#include "qjsonrpcservice_p.h"
#include "qjsonrpcservice.h"

QJsonRpcService::QJsonRpcService(QObject *parent)
    : QObject(*new QJsonRpcServicePrivate(this), parent)
{
}

QJsonRpcService::~QJsonRpcService()
{
}

QJsonRpcSocket *QJsonRpcService::senderSocket()
{
    Q_D(QJsonRpcService);
    if (d->socket)
        return d->socket.data();
    return 0;
}

int convertVariantTypeToJSType(int type)
{
    switch (type) {
    case QMetaType::Int:
    case QMetaType::UInt:
    case QMetaType::Double:
    case QMetaType::Long:
    case QMetaType::LongLong:
    case QMetaType::Short:
    case QMetaType::Char:
    case QMetaType::ULong:
    case QMetaType::ULongLong:
    case QMetaType::UShort:
    case QMetaType::UChar:
    case QMetaType::Float:
        return QMetaType::Double;    // all numeric types in js are doubles
        break;

    default:
        break;
    }

    return type;
}

int QJsonRpcServicePrivate::qjsonRpcMessageType = qRegisterMetaType<QJsonRpcMessage>("QJsonRpcMessage");
void QJsonRpcServicePrivate::cacheInvokableInfo()
{
    Q_Q(QJsonRpcService);
    const QMetaObject *obj = q->metaObject();
    int startIdx = q->staticMetaObject.methodCount(); // skip QObject slots
    for (int idx = startIdx; idx < obj->methodCount(); ++idx) {
        const QMetaMethod method = obj->method(idx);
        if ((method.methodType() == QMetaMethod::Slot &&
             method.access() == QMetaMethod::Public) ||
             method.methodType() == QMetaMethod::Signal) {

#if QT_VERSION >= 0x050000
            QByteArray signature = method.methodSignature();
            QByteArray methodName = method.name();
#else
            QByteArray signature = method.signature();
            QByteArray methodName = signature.left(signature.indexOf('('));
#endif
            if (signature.contains("QVariant"))
                invokableMethodHash[methodName].append(idx);
            else
                invokableMethodHash[methodName].prepend(idx);

            QList<int> parameterTypes;
            QList<int> jsParameterTypes;
            QStringList parameterNames;
#if QT_VERSION >= 0x050000
            parameterTypes << method.returnType();
#else
            parameterTypes << QMetaType::type(method.typeName());
#endif
            foreach(QByteArray parameterType, method.parameterTypes()) {
                parameterTypes << QMetaType::type(parameterType);
                jsParameterTypes << convertVariantTypeToJSType(QMetaType::type(parameterType));
            }

            foreach (QByteArray parameterName, method.parameterNames())
                parameterNames.append(parameterName);

            parameterNamesHash[idx] = parameterNames;
            parameterTypeHash[idx] = parameterTypes;
            jsParameterTypeHash[idx] = jsParameterTypes;
        }
    }
}

bool variantAwareCompare(const QList<int> &argumentTypes, const QList<int> &jsParameterTypes)
{
    if (argumentTypes.size() != jsParameterTypes.size())
        return false;

    for (int i = 0; i < argumentTypes.size(); ++i) {
        if (argumentTypes.at(i) == jsParameterTypes.at(i))
            continue;
        else if (jsParameterTypes.at(i) == QMetaType::QVariant)
            continue;
        else if (argumentTypes.at(i) == QMetaType::QVariantList) {
            if (jsParameterTypes.at(i) == QMetaType::QStringList)
                continue;

            if (jsParameterTypes.at(i) == QMetaType::QVariantList)
                continue;

            return false;
        } else
            return false;
    }

    return true;
}

//QJsonRpcMessage QJsonRpcService::dispatch(const QJsonRpcMessage &request) const
bool QJsonRpcService::dispatch(const QJsonRpcMessage &request)
{
    Q_D(QJsonRpcService);
    if (request.type() != QJsonRpcMessage::Request &&
        request.type() != QJsonRpcMessage::Notification) {
        QJsonRpcMessage error =
            request.createErrorResponse(QJsonRpc::InvalidRequest, "invalid request");
        Q_EMIT result(error);
        return false;
    }

    QByteArray method = request.method().section(".", -1).toLatin1();
    if (!d->invokableMethodHash.contains(method)) {
        QJsonRpcMessage error =
            request.createErrorResponse(QJsonRpc::MethodNotFound, "invalid method called");
        Q_EMIT result(error);
        return false;
    }

    int idx = -1;
    QList<int> parameterTypes;
    QList<int> indexes = d->invokableMethodHash.value(method);

    QVariantList arguments;
    QList<int> argumentTypes;
    if (!request.params().isObject()) {
        arguments = request.params().toArray().toVariantList();
        foreach (QVariant argument, arguments)
            argumentTypes.append(static_cast<int>(argument.type()));
    }

    foreach (int methodIndex, indexes) {
        if (request.params().isObject()) {  // named parameters
            QJsonObject namedParametersObject = request.params().toObject();
            QStringList namedParameters = namedParametersObject.keys();
            QStringList parameterNames = d->parameterNamesHash[methodIndex];
            if (namedParameters.size() > parameterNames.size())
                continue;

            foreach (QString namedParameter, namedParameters) {
                if (!parameterNames.contains(namedParameter))
                    continue;
            }

            // otherwise we have a potential match
            foreach (QString parameterName, parameterNames) {
                QVariant variant =  namedParametersObject.value(parameterName).toVariant();
                arguments.append(variant);
                argumentTypes.append(static_cast<int>(variant.type()));
            }
        }

        if (variantAwareCompare(argumentTypes, d->jsParameterTypeHash[methodIndex])) {
            parameterTypes = d->parameterTypeHash[methodIndex];
            idx = methodIndex;
            break;
        }
    }

    if (idx == -1) {
        QJsonRpcMessage error =
            request.createErrorResponse(QJsonRpc::InvalidParams, "invalid parameters");
        Q_EMIT result(error);
        return false;
    }

    QVarLengthArray<void *, 10> parameters;
    parameters.reserve(parameterTypes.count());

    ObjectCreator objectCreator;
    // first argument to metacall is the return value
    QMetaType::Type returnType = static_cast<QMetaType::Type>(parameterTypes[0]);
    QVariant returnValue(returnType == QMetaType::Void ?
                             QVariant() : QVariant(returnType, objectCreator.create(returnType)));

    if (returnType == QMetaType::QVariant)
        parameters.append(&returnValue);
    else
        parameters.append(returnValue.data());

    // compile arguments
    for (int i = 0; i < parameterTypes.size() - 1; ++i) {
        int parameterType = parameterTypes[i + 1];
        const QVariant &argument = arguments.at(i);
        if (!argument.isValid()) {
            // pass in a default constructed parameter in this case
            parameters.append(objectCreator.create(parameterType));
        } else {
            if (argument.userType() != parameterType &&
                parameterType != QMetaType::QVariant &&
                const_cast<QVariant*>(&argument)->canConvert(static_cast<QVariant::Type>(parameterType)))
                const_cast<QVariant*>(&argument)->convert(static_cast<QVariant::Type>(parameterType));
            parameters.append(const_cast<void *>(argument.constData()));
        }
    }

    bool success =
        const_cast<QJsonRpcService*>(this)->qt_metacall(QMetaObject::InvokeMetaMethod, idx, parameters.data()) < 0;
    if (!success) {
        QString message = QString("dispatch for method '%1' failed").arg(method.constData());
        QJsonRpcMessage error =
            request.createErrorResponse(QJsonRpc::InvalidRequest, message);
        Q_EMIT result(error);
        return false;
    }

    Q_EMIT result(request.createResponse(QJsonValue::fromVariant(returnValue)));
    return true;
}

void *ObjectCreator::create(int type)
{
#if QT_VERSION >= 0x050000
    void *value = QMetaType::create(type);
#else
    void *value = QMetaType::construct(type);
#endif

    m_objects.append(qMakePair(value, type));
    return value;
}

ObjectCreator::~ObjectCreator()
{
    QVarLengthArray<QPair<void*, int>, prealloc>::const_iterator it;
    for (it = m_objects.constBegin(); it != m_objects.constEnd(); ++it)
        QMetaType::destroy(it->second, it->first);
    m_objects.clear();
}
