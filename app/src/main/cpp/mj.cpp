#include <jni.h>
#include <string>
#include "include/main.h"
#include <android/log.h>
#include <assert.h>

using namespace std;
extern "C" JNIEXPORT jstring

JNICALL stringFromMJ(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello MJ";
    Week week = Week::Mon;
    switch (week) {
        case Week::Mon:
            LOGE("mon========>%d", AGE);
            break;
    }
    return env->NewStringUTF(hello.c_str());
}


static JNINativeMethod gMethods[] = {
        {"stringFromMJ", "()Ljava/lang/String;", (void*)stringFromMJ},
};

static int registerNativeMethods(JNIEnv* env
        , const char* className
        , JNINativeMethod* gMethods, int numMethods) {
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

/*
* 为所有类注册本地方法
*/
static int registerNatives(JNIEnv* env) {
    int re = registerNativeMethods(env, JNIREG_CLASS,gMethods,
                                   sizeof(gMethods)/sizeof(gMethods[0]));
    return re;
}

/*
* System.loadLibrary("lib")时会调用
* 如果成功返回JNI版本, 失败返回-1
*/
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env = NULL;
    jint result = -1;
    if ((vm)->GetEnv((void**) &env, JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    assert(env != NULL);
    if (!registerNatives(env)) {//注册
        return -1;
    }
    //成功
    result = JNI_VERSION_1_6;
    return result;
}