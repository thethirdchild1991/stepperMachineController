#ifndef CMDS_H
#define CMDS_H

#include <cstdint>
#include <memory>
#include <QString>
#include <QJsonObject>


#ifdef DEBUG_IO
    #include <QDebug>
#endif

#include "cmdabstract.h"

namespace CMDs{


    class CMD_MOVE_mSTEPS : public virtual CMDAbstract {
        public:
        ~CMD_MOVE_mSTEPS() override {
            qDebug() << "Destructor of CMD_MOVE_mSTEPS";
        }

        void execute() override {
            qDebug() << "From CMD_MOVE_mSTEPS ";
        }
    };

    class CMD_MOVE_mm : public virtual CMDAbstract {
        public:
        ~CMD_MOVE_mm() override {
            qDebug() << "Destructor of CMD_MOVE_mm";
        }
        void execute() override {
            qDebug() << "From CMD_MOVE_mm";
        }
    };

    class CMD_SET : public virtual CMDAbstract {
        public:
        ~CMD_SET() override {
            qDebug() << "Destructor of CMD_SET";
        }
        void execute() override {
            qDebug() << "From CMD_SET";
        }
    };

    class CMD_GET : public virtual CMDAbstract {
        public:
        ~CMD_GET() override {
            qDebug() << "Destructor of CMD_GET";
        }
        void execute() override {
            qDebug() << "From CMD_GET";
        }
    };

    class CMD_SET_ZERO : public virtual CMDAbstract {
        public:
        ~CMD_SET_ZERO() override {
            qDebug() << "Destructor of CMD_SET_ZERO";
        }
        void execute() override {
            qDebug() << "From CMD_SET_ZERO";
        }
    };

    class CMD_BACK_TO_ZERO : public virtual CMDAbstract {
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
