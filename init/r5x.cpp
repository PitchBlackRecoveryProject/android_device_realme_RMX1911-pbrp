/*
   Copyright (c) 2015, The Linux Foundation. All rights reserved.
   Copyright (C) 2016 The CyanogenMod Project.
   Copyright (C) 2019-2020 The LineageOS Project.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <android-base/logging.h>
#include <android-base/properties.h>

#include "property_service.h"
#include "log.h"
#include <string>
#include <fstream>

namespace android {
namespace init {

void load_RMX1911() {
      property_set("ro.product.model", "Realme 5");
      property_set("ro.build.product", "RMX1911");
      property_set("ro.product.device", "RMX1911");

}

void load_RMX1925() {
      property_set("ro.product.model", "Realme 5s");
      property_set("ro.build.product", "RMX1925");
      property_set("ro.product.device", "RMX1925");

}

void load_RMX1927() {
      property_set("ro.product.model", "Realme 5 NFC");
      property_set("ro.build.product", "RMX1927");
      property_set("ro.product.device", "RMX1927");

}

void load_RMX2030() {
      property_set("ro.product.model", "Realme 5i");
      property_set("ro.build.product", "RMX2030");
      property_set("ro.product.device", "RMX2030");

}

void vendor_load_properties()
{
    std::ifstream infile("/proc/oppoVersion/prjVersion");
    std::string prjVersion;
    getline(infile, prjVersion);

    std::ifstream fin;
    std::string buf;
    fin.open("/proc/cmdline");
    while (std::getline(fin, buf, ' '))
      if (buf.find("board_id") != std::string::npos)
          break;
    fin.close();

    if (prjVersion == "19743")
    {
        load_RMX2030();
    }
    else if (prjVersion == "19632")
    {
        load_RMX1927();
    }
    else
    {
        if (buf.find("S86125AA1") != std::string::npos) {
            load_RMX1925();
        } else {
            load_RMX1911();
        }
    }
}
}  // namespace init
}  // namespace android
