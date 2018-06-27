package com.example.nick.ndkdemo;

/**
 * *  user: majun
 * *  email:maj001@qianhai.com.cn
 * *  time:18-6-21
 **/
public class NDKUtils {

    static {
        System.loadLibrary("native-lib");
    }

    public native static String stringFromJNI();
    public native static String stringFromMJ();
}
