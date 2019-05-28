#ifndef CMDS_H
#define CMDS_H

#include <cstdint>
#include <QDebug>

namespace CMDs{

    /* CMD STRUCT
     *  json {
     *      CMD_CODE : CODE,
     *      CMD_PARAM : {
     *          param_name : name,
     *          param_value : value
     *      }
     * }
     *
     */


    enum class CMDs_NAMES{
        MOVE_mSTEPS,    //move N microsteps
        MOVE_mm,        //move N milimeters
        SET,            //set parameter value
        GET,            //get parameter value
        SET_ZERO,       //remember ZERO point
        BACK_TO_ZERO    //return to zero point
    };

    using CMD_DATA_t = std::pair<int, int>;

    struct CMD_DATA{
        CMDs_NAMES CODE;
        CMD_DATA_t DATA;
    };


//    static void execute( CMDs_NAMES cmdType, CMD_DATA_t param ){

//    }
    static void makeUStep(){}
    static void makeMMStep(){}
    static void setParameter( CMD_DATA_t param ){}
    static CMD_DATA_t getParameter( CMD_DATA_t param ){}
    static void setZero(){}
    static void backToZero(){}

    class CMD {
        public:
            explicit CMD( CMDs_NAMES code ) : mCode(code) {}
            virtual ~CMD() = 0;

            virtual void execute( CMD_DATA_t param ) = 0;

            void type( CMDs_NAMES value ) { mType = value; }
            CMDs_NAMES type() const { return mType; }

            static CMD* createCMD( CMD_DATA& cmd );


        protected:
            CMDs_NAMES mCode;
            CMD_DATA_t mData;
    };

    class CMD_MOVE{
        public:
            CMD_MOVE( CMD_DATA_t delta ) :  mDelta{delta} {}
        protected:
            CMD_DATA_t dec( CMD_DATA_t param ){
                return param - mDelta;
            }
            CMD_DATA_t mDelta;
    };

    class CMD_MOVE_mSTEPS : public CMD_MOVE, virtual public CMD{
        public:
            explicit CMD_MOVE_mSTEPS( CMD_DATA_t delta ) : CMD_MOVE(delta), CMD ( CMDs_NAMES::MOVE_mSTEPS ) {}
            void execute( CMD_DATA_t param ) override{
                while(param > 0){
                    makeUStep();
                    param = dec(param);
                }
            }
    };

    class CMD_MOVE_mm {
    };

    class CMD_SET : virtual public CMD{
        public:
            void execute( CMD_DATA_t param ) override{
                setParameter( param );
            }
    };

    class CMD_GET : virtual public CMD{
        public:
            void execute( CMD_DATA_t param ) override{
                getParameter( param );
            }
    };

    class CMD_SET_ZERO : virtual public CMD{
        public:
            void execute( CMD_DATA_t param ) override{

        }
    };

    class CMD_BACK_TO_ZERO{
    };


};

#endif // CMDS_H
