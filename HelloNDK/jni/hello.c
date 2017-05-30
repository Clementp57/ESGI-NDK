//
// Created by Clément Peyrabere on 29/05/2017.
//

#include <string.h> #include <jni.h>
jstring Java_com_example_hellondk_MainActivity_invokeNativeFunction ( JNIEnv* env,jobject thiz ){
    return (*env)->NewStringUTF(env , " HELLO FROM NDK");
}