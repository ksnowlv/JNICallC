/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_ksnowlv_jnicallc_JavaPerson */

#ifndef _Included_com_ksnowlv_jnicallc_JavaPerson
#define _Included_com_ksnowlv_jnicallc_JavaPerson
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_ksnowlv_jnicallc_JavaPerson
 * Method:    init
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_ksnowlv_jnicallc_JavaPerson_init
  (JNIEnv *, jobject);

/*
 * Class:     com_ksnowlv_jnicallc_JavaPerson
 * Method:    finalizer
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ksnowlv_jnicallc_JavaPerson_finalizer
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_ksnowlv_jnicallc_JavaPerson
 * Method:    native_getAge
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_ksnowlv_jnicallc_JavaPerson_native_1getAge
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_ksnowlv_jnicallc_JavaPerson
 * Method:    native_setAge
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_ksnowlv_jnicallc_JavaPerson_native_1setAge
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     com_ksnowlv_jnicallc_JavaPerson
 * Method:    native_getName
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_ksnowlv_jnicallc_JavaPerson_native_1getName
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_ksnowlv_jnicallc_JavaPerson
 * Method:    native_setName
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_ksnowlv_jnicallc_JavaPerson_native_1setName
  (JNIEnv *, jobject, jlong, jstring);

#ifdef __cplusplus
}
#endif
#endif
