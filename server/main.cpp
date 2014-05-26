#include <QCoreApplication>
#include "qjsonrpcservice.h"

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);

    QJsonRpcLocalServiceProvider rpcServer;
    rpcServer.addService(new TestService);
    if (!rpcServer.listen("/tmp/testservice")) {
        qDebug() << "can't start local server: " << rpcServer.errorString();
        return -1;
    }

    return a.exec();
}
