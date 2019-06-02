#include "server.h"

#ifdef DEBUG_IO
#include <QDebug>
#endif

Server::Server()
{
    mTCPServer = new QTcpServer(this);

    connect( mTCPServer, &QTcpServer::newConnection, this, &Server::onNewConnection);

    mTCPServer->listen(QHostAddress::LocalHost, 8080);
}

void Server::onServerStarted(){

#ifdef DEBUG_IO
    qDebug() << "TCP Server Started";
#endif

}

void Server::onNewConnection(){

#ifdef DEBUG_IO
    qDebug() << "Hi newConnection";
#endif

    mTcpServerConnection = mTCPServer->nextPendingConnection();


    connect( mTcpServerConnection, &QTcpSocket::readyRead, this, &Server::onNewMessage );
    connect( mTcpServerConnection, &QTcpSocket::disconnected, mTcpServerConnection, &QTcpSocket::deleteLater);

}

void Server::onNewMessage(){
    qDebug() << "New Message";

    auto buffer = mTcpServerConnection->readAll();

    QDataStream in(&buffer, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_5_11);

    CMDs::CMD_t data;

    in >> data;

    emit newCMD(data);


    qDebug() << (data.first == CMDs::CMDs_NAMES::MOVE_mm)
             << (data.second.first == CONFIGS::configsNames::microStep)
             << data.second.second;

}
