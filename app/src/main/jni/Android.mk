LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := jniPerson
LOCAL_SRC_FILES := com_ksnowlv_jnicallc_JavaPerson.cpp Person.cpp

LOCAL_LDLIBS:=-L$(SYSROOT)/usr/lib -llog

APP_STL = c++_static

include $(BUILD_SHARED_LIBRARY)

