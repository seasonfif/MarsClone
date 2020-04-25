//
// Created by seasonfif on 2020-04-25.
//

#ifndef SOGOUMARS_MARS_H
#define SOGOUMARS_MARS_H


#include <jni.h>
#include "comn/log.h"
#include <pthread.h>

class Mars {

    public:

        jstring setIp(const char *ip);

        void enableDebug(bool debug);

        void connect(const char *host, int priority);

    private:

        const char *ip;

        bool debug;
};


#endif //SOGOUMARS_MARS_H
