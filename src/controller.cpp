#include "controller.h"

Controller::Controller()
{    
    mServer = new Server();
    mConfigStorage = new ConfigsStorage(mConfigPath);

    connect( mServer, &Server::newCMD, this, &Controller::newCMD );
}


void Controller::newCMD( CMDs::CMD_t comandData ){

    mCmd = CMDs::CMDAbstract::createCMD( comandData, std::make_shared<ConfigsStorage>(mConfigStorage) );

    mCmd->execute();

}

