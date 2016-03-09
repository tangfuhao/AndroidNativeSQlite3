#include <jni.h>
#include "databaseWrapper.h"




extern "C" {

JNIEXPORT jint JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_DbNative_openDB(JNIEnv *env,
                                                                             jobject instance,
                                                                             jstring dbPath_) {
    const char *dbPath = env->GetStringUTFChars( dbPath_, 0);

    DatabaseWrappper *db = new DatabaseWrappper();
    bool ret = db->create(dbPath);

    env->ReleaseStringUTFChars(dbPath_, dbPath);
    return ret?(jint)db : 0;
}

JNIEXPORT jboolean JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_DbNative_releaseDB(JNIEnv *env,
                                                                                jobject instance,
                                                                                jint cppObject) {
    DatabaseWrappper *db = (DatabaseWrappper*)cppObject;
    delete db;
    return (jboolean)true;
}

JNIEXPORT jboolean JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_DbNative_createTable(JNIEnv *env,
                                                                                  jobject instance,
                                                                                  jint cppObject,
                                                                                  jstring sql_) {
    const char *sql = env->GetStringUTFChars(sql_, 0);

    DatabaseWrappper *db = (DatabaseWrappper*)cppObject;
    bool ret = db->createTable(sql);

    env->ReleaseStringUTFChars(sql_, sql);
}

JNIEXPORT jboolean JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_DbNative_add(JNIEnv *env,
                                                                          jobject instance,
                                                                          jint cppObject,
                                                                          jstring sql_) {
    const char *sql = env->GetStringUTFChars(sql_, 0);

    DatabaseWrappper *db = (DatabaseWrappper*)cppObject;
    bool ret = db->add(sql);
    env->ReleaseStringUTFChars(sql_, sql);

    return (jboolean)ret;
}

JNIEXPORT jboolean JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_DbNative_delete(JNIEnv *env,
                                                                             jobject instance,
                                                                             jint cppObject,
                                                                             jstring sql_) {
    const char *sql = env->GetStringUTFChars(sql_, 0);

    DatabaseWrappper *db = (DatabaseWrappper*)cppObject;
    bool ret = db->del(sql);

    env->ReleaseStringUTFChars(sql_, sql);

    return (jboolean)ret;
}

JNIEXPORT jboolean JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_DbNative_update(JNIEnv *env,
                                                                             jobject instance,
                                                                             jint cppObject,
                                                                             jstring sql_) {
    const char *sql = env->GetStringUTFChars(sql_, 0);

    DatabaseWrappper *db = (DatabaseWrappper*)cppObject;
    bool ret = db->update(sql);

    env->ReleaseStringUTFChars(sql_, sql);
    return (jboolean)ret;
}

JNIEXPORT jint JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_DbNative_query(JNIEnv *env,
                                                                            jobject instance,
                                                                            jint cppObject,
                                                                            jstring sql_) {
    const char *sql = env->GetStringUTFChars(sql_, 0);

    DatabaseWrappper *db = (DatabaseWrappper*)cppObject;
    CursorWrapper *cwp = db->query(sql);

    env->ReleaseStringUTFChars(sql_, sql);

    return (jint)cwp;
}





JNIEXPORT jstring JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_DbNative_test(JNIEnv *env,
                                                                           jobject instance) {
    char* returnValue = "Hello World";
    return env->NewStringUTF(returnValue);
}








JNIEXPORT jboolean JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_CursorNative_releaseNative(JNIEnv *env,
                                                                                        jobject instance,
                                                                                        jint cppObject) {
    CursorWrapper *cwp = (CursorWrapper*)cppObject;
    delete cwp;
}

JNIEXPORT jint JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_CursorNative_getIntNative(JNIEnv *env,
                                                                                       jobject instance,
                                                                                       jint cppObject,
                                                                                       jint index) {

    CursorWrapper *cwp = (CursorWrapper*)cppObject;
    return (jint)cwp->getInt(index);

}

JNIEXPORT jint JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_CursorNative_getColumnCountNative(
        JNIEnv *env, jobject instance, jint cppObject) {

    CursorWrapper *cwp = (CursorWrapper*)cppObject;
    return (jint)cwp->getColumnCount();
}

JNIEXPORT jint JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_CursorNative_getColumnIndexNative(
        JNIEnv *env, jobject instance, jint cppObject, jstring columName_) {
    const char *columName = env->GetStringUTFChars(columName_, 0);

    CursorWrapper *cwp = (CursorWrapper*)cppObject;
    int ret = cwp->getColumnIndex(columName);

    env->ReleaseStringUTFChars(columName_, columName);
    return (jint)ret;
}

JNIEXPORT jint JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_CursorNative_getCountNative(
        JNIEnv *env, jobject instance, jint cppObject) {

    CursorWrapper *cwp = (CursorWrapper*)cppObject;
    return (jint)cwp->getCount();
}

JNIEXPORT jboolean JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_CursorNative_nextNative(JNIEnv *env,
                                                                                     jobject instance,
                                                                                     jint cppObject) {
    CursorWrapper *cwp = (CursorWrapper*)cppObject;
    return (jboolean)cwp->next();

}

JNIEXPORT jboolean JNICALL
Java_main_java_sqlite3_com_android_tang_androidnativesqlite3_CursorNative_resetNative(JNIEnv *env,
                                                                                      jobject instance,
                                                                                      jint cppObject) {
    CursorWrapper *cwp = (CursorWrapper*)cppObject;
    return (jboolean)cwp->reset();

}


}