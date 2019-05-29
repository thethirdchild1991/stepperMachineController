#include <QCoreApplication>

#ifdef DEBUG_IO
    #include <QDebug>
#endif

#include "Configs.h"
#include "CMDs.h"


using namespace CMDs;
int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
    {
        CMD_t testCMDData = {CMDs_NAMES::MOVE_mSTEPS,{0,0}};

        auto testCMD = CMD::createCMD( testCMDData );
        testCMD->execute();
    }
//    delete testCMD;

//    return a.exec();
}
