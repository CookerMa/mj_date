//
// Created by nick on 18-6-21.
//
const int AGE = 25 ;
#ifndef NDKDEMO_MAIN_H
#define NDKDEMO_MAIN_H
enum class Week{Mon,Tue,Fri,Sun} week;
#endif //NDKDEMO_MAIN_H


#define  LOG_TAG    "NDKDemo"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define JNIREG_CLASS "com/example/nick/ndkdemo/NDKUtils" //定义native方法的java文件