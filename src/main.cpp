#include <QCoreApplication>
#ifdef DEBUG_IO
    #include <QDebug>
#endif

//#include "server.h"
#include "controller.h"




//using namespace CMDs;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    std::unique_ptr<Server> server = std::make_unique<Server>();
//    Server server;
    Controller controller;

    return a.exec();
}
