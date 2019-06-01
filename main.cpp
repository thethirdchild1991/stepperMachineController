#include <QCoreApplication>



#ifdef DEBUG_IO
    #include <QDebug>
#endif

#include "server.h"
#include "client.h"



//using namespace CMDs;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    Client client;


    CMDs::CMD_t testCMDData =   {
                                    CMDs::CMDs_NAMES::MOVE_mm,
                                    {
                                        CONFIGS::configsNames::microStep,
                                        0
                                    }
                                };

    client.sendCmd( testCMDData );

//    {
//        CMD_t testCMDData = {CMDs_NAMES::MOVE_mSTEPS,{0,0}};

//        auto testCMD = CMD::createCMD( testCMDData );
//        testCMD->execute();
//    }
//    delete testCMD;

    return a.exec();
}
