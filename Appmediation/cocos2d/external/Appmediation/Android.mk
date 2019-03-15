LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)

LOCAL_MODULE := appmediation_static

LOCAL_SRC_FILES := $(LOCAL_PATH)/src/AMSDK.cpp \

LOCAL_C_INCLUDES:= $(LOCAL_PATH)/include 

LOCAL_STATIC_LIBRARIES := cocos2dx_static

include $(BUILD_STATIC_LIBRARY)		
