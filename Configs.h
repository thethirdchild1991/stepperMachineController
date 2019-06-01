#ifndef CONFIGS_H
#define CONFIGS_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include "ConfigHelper.h"

using namespace CONFIGS;

class ConfigsStorage
{    

public:
    explicit ConfigsStorage( const QString& filename ) : m_filename(filename)
    {
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

    config_t microStep() const { return get( configsNames::microStep ); }
//public:
//    void microStep( config_t value ) { add( configsNames::microStep, value ); }

    void load(){
        QFile configsFile( m_filename );

        if (!configsFile.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open save file.");
            return;
        }

        QJsonDocument configsDoc( QJsonDocument::fromJson( configsFile.readAll() ) );

        parseJson(configsDoc.object());
        configsFile.close();
    }
    void save() const {
        QFile configsFile( m_filename );

        if (!configsFile.open(QIODevice::WriteOnly)) {
            qWarning("Couldn't open save file.");
            return;
        }

        QJsonObject configObject;

        QJsonDocument configDoc(configObject);

        configsFile.write(configDoc.toJson());
        configsFile.close();

    }


private:

    void add( const configsNames name, const config_t value );
    config_t get( const configsNames configName ) const { return m_configs.value( configName ); }

    void parseJson( const QJsonObject& jsonObject ){
        for( auto key : jsonObject.keys() ){
            auto value = toConfig_t(jsonObject.value(key));
            auto configName = toConfigName(key);
            add(configName, value);
        }
    }


//    void operator>>( QJsonObject json ){}
//    void operator<<( QJsonObject json ){}

    QMap<configsNames, config_t> m_configs;
    QString m_filename;
};

#endif // CONFIGS_H
