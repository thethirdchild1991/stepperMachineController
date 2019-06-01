#ifndef CMDABSTRACT_H
#define CMDABSTRACT_H

#include "cmdtype.h"

namespace CMDs {

class CMDAbstract {
    public:

        virtual ~CMDAbstract() = 0;
        virtual void execute() = 0;

        static std::unique_ptr<CMDAbstract> createCMD( CMD_t& cmd );

    protected:
        CMD_t mCMD;
};


}

#endif // CMDABSTRACT_H
