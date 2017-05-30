LOCAL_PATH := $(call my-dir)
MY_PATH := $(LOCAL_PATH)
include $(call all-subdir-makefiles)
include $(CLEAR_VARS)
LOCAL_MODULE := main
SDL_PATH := ./SDL

LOCAL_C_INCLUDES := $(MY_PATH)/$(SDL_PATH)/include

#Add your application source files here
LOCAL_SRC_FILES := src/main/android/SDL_android_main.c \
	../main.c

LOCAL_SHARED_LIBRARIES := SDL2

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)