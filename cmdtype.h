#ifndef CMDTYPE_H
#define CMDTYPE_H

#include <memory>
#include "cmdnames.h"
#include "confignames.h"

namespace CMDs {

using CMD_DATA_t = std::pair<CONFIGS::configsNames, uint8_t>;
using CMD_t = std::pair<CMDs_NAMES,CMD_DATA_t>;

}

#endif // CMDTYPE_H
