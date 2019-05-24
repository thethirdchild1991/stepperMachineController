#include <QCoreApplication>

#ifdef DEBUG_IO
    #include <QDebug>
#endif

#include "Configs.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);





    return a.exec();
}
