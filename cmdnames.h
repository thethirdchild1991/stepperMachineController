#ifndef CMDNAMES_H
#define CMDNAMES_H
#include <cstdint>

namespace CMDs{

enum class CMDs_NAMES : uint8_t{
    MOVE_mSTEPS,    //move N microsteps
    MOVE_mm,        //move N milimeters
    SET,            //set parameter value
    GET,            //get parameter value
    SET_ZERO,       //remember ZERO point
    BACK_TO_ZERO    //return to zero point
};

}

#endif // CMDNAMES_H
