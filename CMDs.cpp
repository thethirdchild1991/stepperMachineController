#include "CMDs.h"

using namespace CMDs;

CMD::~CMD(){
//    qDebug() << "Destructor of CMD";
}

std::unique_ptr<CMD> CMD::createCMD( CMD_t& cmd ){

    std::unique_ptr<CMD> p;

    switch ( cmd.first ) {
        case CMDs_NAMES::MOVE_mSTEPS    : p = std::make_unique<CMD_MOVE_mSTEPS>();  break;
        case CMDs_NAMES::MOVE_mm        : p = std::make_unique<CMD_MOVE_mm>();      break;
        case CMDs_NAMES::SET            : p = std::make_unique<CMD_SET>();          break;
        case CMDs_NAMES::GET            : p = std::make_unique<CMD_GET>();          break;
        case CMDs_NAMES::SET_ZERO       : p = std::make_unique<CMD_SET_ZERO>();     break;
        case CMDs_NAMES::BACK_TO_ZERO   : p = std::make_unique<CMD_BACK_TO_ZERO>(); break;
    }

    return p;
}
