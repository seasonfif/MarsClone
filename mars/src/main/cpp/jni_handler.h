//
// Created by seasonfif on 2020-04-24.
//

#ifndef SOGOUMARS_JNI_HANDLER_H
#define SOGOUMARS_JNI_HANDLER_H

#include <jni.h>
#include "comn/log.h"
#include "mars.h"

namespace JNIHandler {

    static JavaVM *g_jvm = NULL;

    void InitJavaVM(JavaVM* vm);

    JNIEnv* AttachCurrentThread();

    bool RegisterApi(JNIEnv* env);

    static jstring InitMars(JNIEnv *env, jclass clazz, jstring flag);

    static jint Config(JNIEnv *env, jclass clazz, jstring config);
}


#endif //SOGOUMARS_JNI_HANDLER_H
