#ifndef CONFIGS_H
#define CONFIGS_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>

namespace configHelper {
    enum configsNames{
        speed,          //speed
        acceleration,   //acceleration
        dS,             //step in mm
        SOnRotate,      //how much mm in one rotation
        stepsOnRotate,  //how many steps in one rotation
        N,              //driver multiplication
        microStep       //how much mm in one microstep
    };

    using config_t = uint32_t;
    static config_t toConfig_t( const QJsonValue& value ) { return static_cast<config_t>(value.toInt()); }
    static configsNames toConfigName( const QString& name ) { return configsNames::speed; }

}

using namespace configHelper;
class Configs
{    

public:
    explicit Configs( const QString& filename ){
        QFile configsFile( filename );

        if (!configsFile.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open save file.");
            return;
        }

        QJsonDocument configsDoc( QJsonDocument::fromJson( configsFile.readAll() ) );

        parseJson(configsDoc.object());

    }

    config_t speed() const { return get( configsNames::speed ); }
    void speed( config_t value ) { add( configsNames::speed, value ); }

    config_t acceleration() const { return get( configsNames::acceleration ); }
    void acceleration( config_t value ) { add( configsNames::acceleration, value ); }

    config_t dS() const { return get( configsNames::dS ); }
    void dS( config_t value ) { add( configsNames::dS, value ); }

    config_t SOnRotate() const { return get( configsNames::SOnRotate ); }
    void SOnRotate( config_t value ) { add( configsNames::SOnRotate, value ); }

    config_t stepsOnRotate() const { return get( configsNames::stepsOnRotate ); }
    void stepsOnRotate( config_t value ) { add( configsNames::stepsOnRotate, value ); }

    config_t N() const { return get( configsNames::N ); }
    void N( config_t value ) { add( configsNames::N, value ); }

//private:
//    config_t microStep() const { return get( configsNames::microStep ); }
public:
    void microStep( config_t value ) { add( configsNames::microStep, value ); }


private:

    void add( const configsNames name, const config_t value );
    config_t get( const configsNames configName ) const { return m_configs.value( configName ); }

    void parseJson( const QJsonObject& jsonObject ){
        for( auto key : jsonObject.keys() ){
            auto value = configHelper::toConfig_t(jsonObject.value(key));
            auto configName = configHelper::toConfigName(key);
            add(configName, value);
        }
    }

    QMap<configsNames, config_t> m_configs;
};

#endif // CONFIGS_H
