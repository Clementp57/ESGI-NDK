#include <jni.h>
#include <string.h>

extern "C"
JNIEXPORT jint JNICALL

Java_com_example_clementpeyrabere_hellondk_MainActivity_fibo(
        JNIEnv* env,
        jobject /* this */,
        jint n) {
    /*std::string hello = "Hello word";*/
    int fibo = 4;
//    return env->NewStringUTF(hello.c_str());
    return fibo;
}

//Java_com_example_clementpeyrabere_hellondk_MainActivity_fibo (
//        JNIEnv * env,
//        jobject thiz,
//        jint n) {
//    int test = 5;
//    return test;
//}
