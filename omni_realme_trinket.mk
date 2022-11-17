#
# Copyright (C) 2022 The Android Open Source Project
# Copyright (C) 2022 SebaUbuntu's TWRP device tree generator
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit some common Omni stuff.
$(call inherit-product, vendor/omni/config/common.mk)

# Inherit from realme_trinket device
$(call inherit-product, device/realme/realme_trinket/device.mk)

PRODUCT_DEVICE := realme_trinket
PRODUCT_NAME := omni_realme_trinket
PRODUCT_BRAND := Realme
PRODUCT_MODEL := Realme Trinket
PRODUCT_MANUFACTURER := realme

PRODUCT_GMS_CLIENTID_BASE := android-realme

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRIVATE_BUILD_DESC="twrp_realme_trinket-eng 127 SP2A.220405.004 eng.irawan.20220812.210549 test-keys"

BUILD_FINGERPRINT := Realme/twrp_realme_trinket/realme_trinket:127/SP2A.220405.004/irawans08122101:eng/test-keys
