//
// Created by seasonfif on 2020-04-24.
//

#include <jni.h>
#include <string>
#include "log.h"
#include "../jni_handler.h"

using namespace JNIHandler;

extern "C" {

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved) {
    LOGE("JNI_OnLoad");
    JNIEnv* env = NULL;
    JNIHandler::InitJavaVM(jvm);

    env = JNIHandler::AttachCurrentThread();
    if(env == NULL){
        return -1;
    }

    LOGE("jvm->GetEnv");

    if(!JNIHandler::RegisterApi(env)){
        return -1;
    }

    LOGE("RegisterApi");
    return JNI_VERSION_1_6;
}

/*JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved) {
    LOGE("JNI_OnLoad");
    JNIEnv* env = NULL;
    jint status = jvm->GetEnv((void**) &env, JNI_VERSION_1_6);
    if(status != JNI_OK){
        return -1;
    }

    LOGE("jvm->GetEnv");

    if(!JNIHandler::RegisterApi(env)){
        return -1;
    }

    LOGE("RegisterApi");
    return JNI_VERSION_1_6;
}*/

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved)
{
    LOGE("JNI_OnUnload");
}

}

