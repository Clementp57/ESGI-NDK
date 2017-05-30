#include <string.h>
#include <jni.h>

int fibonacci(int);
void callBackMethod(JNIEnv*, jobject, int);
jstring Java_com_damienbannerot_app_Main_invokeNativeFunction( JNIEnv* env,jobject thiz ) {
  return (*env)->NewStringUTF(env , "azazaza HELLO FROM NDK");
}

jint Java_com_damienbannerot_app_Main_fibonacci(JNIEnv* env, jobject thiz, jint n) {
  return fibonacci(n);
}

jint Java_com_damienbannerot_app_Main_fibonacciWithCallback(JNIEnv* env, jobject thiz, jint n) {
  int val = fibonacci(n);
  callBackMethod(env, thiz, val);
  return val;
}

int fibonacci(int n) {
  if (n<=1)
    return n;
  return (fibonacci(n-1))+(fibonacci(n-2));
}

void callBackMethod(JNIEnv* env, jobject thiz, int val) {
  jclass c = (*env)->GetObjectClass(env, thiz);
  jmethodID methID = (*env)->GetMethodID(env, c, "fibonacciCallback", "(I)V");
  if(methID==0) {
    return;
  }
  (*env)->CallVoidMethod(env, thiz, methID, val);
}
