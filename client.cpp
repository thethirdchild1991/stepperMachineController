#include "client.h"

#include <QHostAddress>

#ifdef DEBUG_IO
#include <QDebug>
#endif


Client::Client() : mQTcpSocket( new QTcpSocket(this) )
{
    mQTcpSocket->connectToHost( QHostAddress::LocalHost, 8080);
}

Client::~Client(){
    mQTcpSocket->disconnectFromHost();
}

void Client::sendCmd( CMDs::CMD_t& data ){

    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_11);

    out << data;

    mQTcpSocket->write(buffer);
}

