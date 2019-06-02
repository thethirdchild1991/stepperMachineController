#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include "cmdhelper.h"
#include "CMDs.h"

class Server : public QObject
{
    Q_OBJECT

public:
    Server();
    ~Server() {
        qDebug() << "Server destructor";
    }

    public slots:
    void onNewConnection();
    void onServerStarted();
    void onNewMessage();

    signals:
    void newCMD( CMDs::CMD_t data );

private:
    QTcpServer* mTCPServer = nullptr;
    QTcpSocket* mTcpServerConnection = nullptr;
};

#endif // SERVER_H
