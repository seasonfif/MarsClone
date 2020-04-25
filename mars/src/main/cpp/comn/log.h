//
// Created by seasonfif on 2020-04-24.
//

#ifndef SOGOUMARS_LOG_H
#define SOGOUMARS_LOG_H

#include <android/log.h>

#define TAG    "jnilog" // 这个是自定义的LOG的标识
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__) // 定义LOGD类型

#endif //SOGOUMARS_LOG_H
