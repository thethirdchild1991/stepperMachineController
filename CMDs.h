#ifndef CMDS_H
#define CMDS_H

#include <cstdint>
#include <memory>
#include <QString>
#include <QJsonObject>


#ifdef DEBUG_IO
    #include <QDebug>
#endif

namespace CMDs{

/* CMD STRUCT
* json {
*      CMD_CODE : CODE,
*      CMD_PARAM : {
*          param_name : name,
*          param_value : value
*      }
* }
*
*/
    enum class CMD_JSON_KEYS{
        CMD_CODE,
        PARAM_NAME,
        PARAM_VALUE,
    };

    static CMD_JSON_KEYS toQString( QString& key ){
        QMap<QString, CMD_JSON_KEYS> helper = {
            {QString("CMD_CODE"), CMD_JSON_KEYS::CMD_CODE},
            {QString("PARAM_NAME"), CMD_JSON_KEYS::PARAM_NAME},
            {QString("PARAM_VALUE"), CMD_JSON_KEYS::PARAM_VALUE}
        };
        return helper.value(key);
    }

    enum class CMDs_NAMES {
        MOVE_mSTEPS,    //move N microsteps
        MOVE_mm,        //move N milimeters
        SET,            //set parameter value
        GET,            //get parameter value
        SET_ZERO,       //remember ZERO point
        BACK_TO_ZERO    //return to zero point
    };

    using CMD_DATA_t = std::pair<int, int>;
//    using CMD_t = std::pair<CMDs_NAMES,CMD_DATA_t>;
    class CMD_t{
        public:
            explicit CMD_t( QJsonObject& jsonObject ){
                for(auto key : jsonObject.keys()){

                }
            }
    };

    static CMDs_NAMES toCMDName( QString& name){
        QMap<QString, CMDs_NAMES> namesHelper = {
            {QString("MOVE_mSTEPS"), CMDs_NAMES::MOVE_mSTEPS},
            {QString("MOVE_mm"), CMDs_NAMES::MOVE_mm},
            {QString("SET"), CMDs_NAMES::SET},
            {QString("GET"), CMDs_NAMES::GET},
            {QString("SET_ZERO"), CMDs_NAMES::SET_ZERO},
            {QString("BACK_TO_ZERO"), CMDs_NAMES::BACK_TO_ZERO}
        };
        return namesHelper.value(name);
    }
    static CMD_t toCMD_t( const QJsonObject& jsonObject ) {
        for(auto key : jsonObject.keys() ){
            auto value = jsonObject.value(key);
        }
    }

//    static void execute( CMDs_NAMES cmdType, CMD_DATA_t param ){

//    }

//    static void makeUStep(){}
//    static void makeMMStep(){}
//    static void setParameter( CMD_DATA_t param ){}
//    static CMD_DATA_t getParameter( CMD_DATA_t param ){}
//    static void setZero(){}
//    static void backToZero(){}

    class CMD {
        public:

            virtual ~CMD() = 0;
            virtual void execute() = 0;

            static std::unique_ptr<CMD> createCMD( CMD_t& cmd );

        protected:
            CMD_t mCMD;
    };


    class CMD_MOVE_mSTEPS : public virtual CMD {
        public:
        ~CMD_MOVE_mSTEPS() override {
            qDebug() << "Destructor of CMD_MOVE_mSTEPS";
        }

        void execute() override {
            qDebug() << "From CMD_MOVE_mSTEPS ";
        }
    };

    class CMD_MOVE_mm : public virtual CMD {
        public:
        ~CMD_MOVE_mm() override {
            qDebug() << "Destructor of CMD_MOVE_mm";
        }
        void execute() override {
            qDebug() << "From CMD_MOVE_mm";
        }
    };

    class CMD_SET : public virtual CMD {
        public:
        ~CMD_SET() override {
            qDebug() << "Destructor of CMD_SET";
        }
        void execute() override {
            qDebug() << "From CMD_SET";
        }
    };

    class CMD_GET : public virtual CMD {
        public:
        ~CMD_GET() override {
            qDebug() << "Destructor of CMD_GET";
        }
        void execute() override {
            qDebug() << "From CMD_GET";
        }
    };

    class CMD_SET_ZERO : public virtual CMD {
        public:
        ~CMD_SET_ZERO() override {
            qDebug() << "Destructor of CMD_SET_ZERO";
        }
        void execute() override {
            qDebug() << "From CMD_SET_ZERO";
        }
    };

    class CMD_BACK_TO_ZERO : public virtual CMD {
        public:
        ~CMD_BACK_TO_ZERO() override {
            qDebug() << "Destructor of CMD_BACK_TO_ZERO";
        }
        void execute() override {
            qDebug() << "From CMD_BACK_TO_ZERO";
        }
    };


};

#endif // CMDS_H
