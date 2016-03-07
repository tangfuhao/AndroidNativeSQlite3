#include <jni.h>

JNIEXPORT jstring JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_Test_test(JNIEnv *env,
                                                                       jobject instance) {
    char* returnValue = "Hello World";
    return (*env)->NewStringUTF(env, returnValue);
}