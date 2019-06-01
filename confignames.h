#ifndef CONFIGNAMES_H
#define CONFIGNAMES_H

#include <cstdint>

namespace CONFIGS {

    enum class configsNames : uint8_t{
        speed,          //speed
        acceleration,   //acceleration
        dS,             //step in mm
        SOnRotate,      //how much mm in one rotation
        stepsOnRotate,  //how many steps in one rotation
        N,              //driver multiplication
        microStep       //how much mm in one microstep
    };

}

#endif // CONFIGNAMES_H
