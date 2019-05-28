#ifndef CONFIGHELPER_H
#define CONFIGHELPER_H

#include <QJsonValue>
#include <QMap>
namespace configHelper {
    enum class configsNames{
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
    static configsNames toConfigName( const QString& name ) {
        QMap<QString, configsNames> namesHelper = {
            {QString("speed"),          configsNames::speed },
            {QString("acceleration"),   configsNames::acceleration },
            {QString("dS"),             configsNames::dS },
            {QString("SOnRotate"),      configsNames::SOnRotate },
            {QString("stepsOnRotate"),  configsNames::stepsOnRotate },
            {QString("N"),              configsNames::N },
            {QString("microStep"),      configsNames::microStep }
        };
        return namesHelper.value(name);
    }

}


#endif // CONFIGHELPER_H
