#ifndef CMDHELPER_H
#define CMDHELPER_H

#include "cmdtype.h"
#include <QDataStream>

namespace CMDs {


inline QDataStream &operator<<(QDataStream &out, const CMDs::CMD_t &data){
    out << static_cast<uint8_t>(data.first)
        << static_cast<uint8_t>(data.second.first)
        << static_cast<uint8_t>(data.second.second);
    return out;
}

inline QDataStream &operator>>(QDataStream &in, CMDs::CMD_t &data)
{
    uint8_t tmp[3];
    in >> tmp[0] >> tmp[1] >> tmp[2];
    data.first = static_cast<CMDs::CMDs_NAMES>(tmp[0]);
    data.second.first = static_cast<CONFIGS::configsNames>(tmp[1]);
    data.second.second = tmp[2];

    return in;

}


}

#endif // CMDHELPER_H
