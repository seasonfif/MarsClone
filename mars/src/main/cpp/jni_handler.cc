//
// Created by seasonfif on 2020-04-24.
//

#include "jni_handler.h"

void JNIHandler::InitJavaVM(JavaVM *vm) {

    g_jvm = vm;

}

JNIEnv* JNIHandler::AttachCurrentThread() {

    JNIEnv* env = NULL;

    jint status = g_jvm->AttachCurrentThread(&env, NULL);
    if(status != JNI_OK){
        LOGE("JNIEnv create fail");
    }
    return env;

}

bool JNIHandler::RegisterApi(JNIEnv *env) {

    static const JNINativeMethod jni_Method[] = {
            {
                    .name = "initMars",
                    .signature = "(Ljava/lang/String;)Ljava/lang/String;",
                    .fnPtr = (void*)InitMars,
            },

            {
                    .name = "config",
                    .signature = "(Ljava/lang/String;)I",
                    .fnPtr = reinterpret_cast<void*>(&Config),
            }
    };

    static const char* kClassName = "com/seasonfif/mars/JNIHandler";

    jclass jcls = env->FindClass(kClassName);

    jint status = env->RegisterNatives(jcls, jni_Method, sizeof(jni_Method)/ sizeof(jni_Method[0]));
    return status >= 0;
}

jstring JNIHandler::InitMars(JNIEnv *env, jclass clazz, jstring flag) {

    Mars().setIp("192.168.1.1");

    const char *bytes = env->GetStringUTFChars(flag, JNI_FALSE);
    return env->NewStringUTF(bytes);
}

jint JNIHandler::Config(JNIEnv *env, jclass clazz, jstring config) {
    LOGE("config:%s", env->GetStringUTFChars(config, JNI_FALSE));
    Mars().enableDebug(true);
    return 2;
}
