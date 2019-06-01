#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include "cmdhelper.h"
#include "CMDs.h"

class Server : public QObject
{
public:
    Server();

    public slots:
    void onNewConnection();
    void onServerStarted();
    void onNewMessage();


private:
    QTcpServer* mTCPServer = nullptr;
    QTcpSocket* mTcpServerConnection = nullptr;
};

#endif // SERVER_H
