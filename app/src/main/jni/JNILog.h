//
// Created by ksnowlv on 2019/4/11.
//

#ifndef HELLOJNIFORJAVA_JNILOG_H
#define HELLOJNIFORJAVA_JNILOG_H

#include <android/log.h>

#define TAG "------JNICallC++" // 这个是自定义的LOG的标识
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型


#endif //HELLOJNIFORJAVA_JNILOG_H
