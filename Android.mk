LOCAL_PATH := $(call my-dir)

ifeq ($(TARGET_DEVICE),r5x)
include $(call all-subdir-makefiles,$(LOCAL_PATH))
endif
