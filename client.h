#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QDataStream>
#include "cmdtype.h"
#include "cmdhelper.h"

class Client : public QObject
{
public:
    Client();
    ~Client();
    void sendCmd(  CMDs::CMD_t& );
private:
    QTcpSocket* mQTcpSocket;
};

#endif // CLIENT_H
