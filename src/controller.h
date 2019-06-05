#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "server.h"
#include "Configs.h"




class Controller : public QObject
{
    Q_OBJECT

public:
    Controller();    

    public slots:
    void newCMD( CMDs::CMD_t );

private:

    void move();

    Server *mServer = nullptr;
    std::shared_ptr<ConfigsStorage> mConfigStorage = nullptr;
    std::unique_ptr<CMDs::CMDAbstract> mCmd = nullptr;

    storagePath_t mConfigPath = "";

};

#endif // CONTROLLER_H
