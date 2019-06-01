#ifndef CONFIGHELPER_H
#define CONFIGHELPER_H

#include "confignames.h"
#include <QJsonValue>
#include <QMap>
namespace CONFIGS {


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
