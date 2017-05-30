#include <string.h>
#include <jni.h>

int fibonacci(int n)
{
   if (n <= 1)
      return n;
   return fibonacci(n-1) + fibonacci(n-2);
}

jstring Java_com_example_app_Main_invokeNativeFunction ( JNIEnv* env,jobject thiz ){
	return (*env)->NewStringUTF(env , " HELLO FROM NDK");
}

jint Java_com_example_app_Main_computeFibo( JNIEnv* env,jobject thiz, jint n) {
    return fibonacci(n);
}

