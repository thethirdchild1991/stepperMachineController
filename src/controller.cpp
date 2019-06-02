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

    move();

}

void Controller::move(){
    auto stepsToDo = mConfigStorage->get(configsNames::steps);
    auto microStepsInMM = mConfigStorage->get(configsNames::microStepsInMM);
    auto mmInMicrostep = 1 / microStepsInMM;
    //how too speed up carriage??


    //speed up carriage
    //movement
    //slow down carriage
}

