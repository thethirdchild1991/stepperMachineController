#ifndef CMDS_H
#define CMDS_H

#include <cstdint>
#include <QDebug>

namespace CMDs{
    enum class CMDs_NAMES{
        MOVE_mSTEPS,    //move N microsteps
        MOVE_mm,        //move N milimeters
        SET,            //set parameter value
        GET,            //get parameter value
        SET_ZERO,       //remember ZERO point
        BACK_TO_ZERO    //return to zero point
    };

    using CMD_PARAM_t = uint32_t;
//    static void execute( CMDs_NAMES cmdType, CMD_PARAM_t param ){

//    }

    class CMD {
        public:

        explicit CMD( CMDs_NAMES type ) : mType(type) {}
        virtual ~CMD(){}

        virtual void execute( CMD_PARAM_t param ){
            qDebug() << "ERROR, from CMD ABSTRACT CLASS";
        }

        void type( CMDs_NAMES value ) { mType = value; }
        CMDs_NAMES type() const { return mType; }


        private:
        CMDs_NAMES mType;
    };

    class CMD_MOVE_mSTEPS : virtual public CMD{};

    class CMD_MOVE_mm : virtual public CMD{};

    class CMD_SET : virtual public CMD{};

    class CMD_GET : virtual public CMD{};

    class CMD_SET_ZERO : virtual public CMD{};

    class CMD_BACK_TO_ZERO : virtual public CMD{};


};

#endif // CMDS_H
