//
// Created by ksnowlv on 2019-04-18.
//

#include"com_ksnowlv_jnicallc_JavaPerson.h"
#include "Person.hpp"
#include "JNILog.h"
#include <string.h>

extern "C"
{

/*
 * Class:     com_ksnowlv_jnicallc_JavaPerson
 * Method:    init
 * Signature: ()I
 */
JNIEXPORT jlong JNICALL Java_com_ksnowlv_jnicallc_JavaPerson_init
  (JNIEnv *, jobject) {

      LOGE("JNI Java_com_ksnowlv_jnicallc_JavaPerson_init");
      Person *person = new Person();
      return (jlong)person;

  }

/*
 * Class:     com_ksnowlv_jnicallc_JavaPerson
 * Method:    finalizer
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ksnowlv_jnicallc_JavaPerson_finalizer
  (JNIEnv *, jobject cls, jlong thisObject) {

    LOGE("JNI Java_com_ksnowlv_jnicallc_JavaPerson_finalizer");

    Person *person = (Person *)thisObject;

    if (NULL != person) {
        delete person;
        person = NULL;
    }

  }

/*
 * Class:     com_ksnowlv_jnicallc_JavaPerson
 * Method:    native_getAge
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_ksnowlv_jnicallc_JavaPerson_native_1getAge
  (JNIEnv *evn, jobject cls, jlong thisObject ) {

    Person *person = (Person *)thisObject;

    LOGE("JNI Java_com_ksnowlv_jnicallc_JavaPerson_native_1getAge= %d", person->age());

    if (NULL != person) {

        return person->age();
    }

    return -1;
  }

/*
 * Class:     com_ksnowlv_jnicallc_JavaPerson
 * Method:    native_setAge
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_ksnowlv_jnicallc_JavaPerson_native_1setAge
  (JNIEnv *env, jobject cls, jlong thisObject, jint age ) {

      LOGE("JNI Java_com_ksnowlv_jnicallc_JavaPerson_native_1setAge = %d", age);

      Person *person = (Person *)thisObject;

      if ( NULL != person ) {
        person->setAge(age);
      }
  }

/*
 * Class:     com_ksnowlv_jnicallc_JavaPerson
 * Method:    native_getName
 * Signature: (J)I
 */
JNIEXPORT jstring JNICALL Java_com_ksnowlv_jnicallc_JavaPerson_native_1getName
  (JNIEnv *env, jobject cls, jlong thisObject) {
      LOGE("JNI Java_com_ksnowlv_jnicallc_JavaPerson_native_1getName");

      Person *person = (Person *)thisObject;

      if ( NULL != person ) {
          const char *name = person->name();
          if ( name != NULL ) {
               // LOGI("JNI name = %s",name);
                return  env->NewStringUTF(name);
           }
       }

    return env->NewStringUTF("");
  }

/*
 * Class:     com_ksnowlv_jnicallc_JavaPerson
 * Method:    native_setName
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_ksnowlv_jnicallc_JavaPerson_native_1setName
  (JNIEnv *env, jobject cls, jlong thisObject, jstring string) {

    LOGE("JNI Java_com_ksnowlv_jnicallc_JavaPerson_native_1setName");

     jclass   clsstring   =   env->FindClass("java/lang/String");  //String
     jstring   code   =   env->NewStringUTF("UTF8"); //"UTF8"
     jmethodID   methodID   =   env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B"); //getBytes(String);
     jbyteArray   byteArray =   (jbyteArray)env->CallObjectMethod(string,methodID,code); // String .getByte("UTF8");
     jsize   length   =   env->GetArrayLength(byteArray);
     jbyte*   bytes   =   env->GetByteArrayElements(byteArray,JNI_FALSE);

    Person *person = (Person *)thisObject;

    if ( NULL != person ) {
       if( length > 0){
            char* buf =   new char[length+1];
            memset(buf,0,length+1);
            memcpy(buf,bytes,length);
            person->setName(buf);
            LOGE("JNI set name = %s",buf);
            delete []buf;
         }else{
            person->setName(NULL);
         }
    }



     env->ReleaseByteArrayElements(byteArray,bytes,0);  //释放内存空间
  }

}

static  JNINativeMethod methods[] = {

        {"init", "()J", (void *)Java_com_ksnowlv_jnicallc_JavaPerson_init},
        {"finalizer", "(J)V", (void *)Java_com_ksnowlv_jnicallc_JavaPerson_finalizer},
        {"native_getAge", "(J)I", (void *)Java_com_ksnowlv_jnicallc_JavaPerson_native_1getAge},
        {"native_setAge", "(JI)V", (void *)Java_com_ksnowlv_jnicallc_JavaPerson_native_1setAge},
        {"native_getName", "(J)Ljava/lang/String;", (void *)Java_com_ksnowlv_jnicallc_JavaPerson_native_1getName},
        {"native_setName", "(JLjava/lang/String;)V", (void *)Java_com_ksnowlv_jnicallc_JavaPerson_native_1setName},
};





static const char * classPathName = "com/ksnowlv/jnicallc/JavaPerson";
/*
 * Register several native methods for one class.
 */
static int registerNativeMethods(JNIEnv* env, const char* className,
                                 JNINativeMethod* gMethods, int numMethods)
{
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        LOGE("JavaPerson Native registration unable to find class '%s'", className);
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        LOGE("JavaPerson RegisterNatives failed for '%s'", className);
        return JNI_FALSE;
    }

    LOGE("JavaPerson registerNativeMethods OK");
    return JNI_TRUE;
}
/*
 * Register native methods for all classes we know about.
 *
 * returns JNI_TRUE on success.
 */
static int registerNatives(JNIEnv* env)
{
    if (!registerNativeMethods(env, classPathName,
                               methods, sizeof(methods) / sizeof(methods[0]))) {
        LOGE("JavaPerson class registerNatives FAIL");
        return JNI_FALSE;
    }

    LOGE("JavaPerson registerNatives OK");
    return JNI_TRUE;
}
// ----------------------------------------------------------------------------
/*
 * This is called by the VM when the shared library is first loaded.
 */

typedef union {
    JNIEnv* env;
    void* venv;
} UnionJNIEnvToVoid;

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    UnionJNIEnvToVoid uenv;
    uenv.venv = NULL;
    jint result = -1;
    JNIEnv* env = NULL;

    LOGE("JNI_OnLoad");
    if (vm->GetEnv(&uenv.venv, JNI_VERSION_1_4) != JNI_OK) {
        LOGE("ERROR: GetEnv failed");
        goto bail;
    }
    env = uenv.env;
    if (registerNatives(env) != JNI_TRUE) {
        LOGE("ERROR: registerNatives failed");
        goto bail;
    }

    result = JNI_VERSION_1_4;

    LOGE("JNI_OnLoad OK");
    bail:
    return result;
}