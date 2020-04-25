//
// Created by seasonfif on 2020-04-25.
//


#include "mars.h"
#include "mars_connect.h"
#include "jni_handler.h"

pthread_t pthread = NULL;

jstring Mars::setIp(const char *jip) {

    ip = jip;

    LOGE("ip=%s", ip);

    connect(ip, 3);

    return nullptr;
}

void Mars::enableDebug(bool jdebug) {
    debug = jdebug;
    LOGE("ip=%s", "debug");
}

void* init(void*){

    JNIEnv* env = NULL;
//    JNIHandler::g_jvm->AttachCurrentThread(&env, NULL);

    MarsConnect::Init();

//    pthread_exit(&pthread);
}

void Mars::connect(const char *host, int priority) {

    int ret = pthread_create(&pthread, NULL, init, NULL);
    if(ret < 0) return;
}
