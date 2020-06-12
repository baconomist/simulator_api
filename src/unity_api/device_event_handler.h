//
// Created by Lucas on 2020-06-12.
//

#pragma once

#include "unity_api.h"
#include "unity_method_definitions.h"

namespace device_events
{
    enum class DeviceType
    {
        Motor = 0,
        VisionSensor = 1
    };

    typedef int (DeviceEventListener)(int device_type, int device_event, ...);

    extern DeviceEventListener *device_event_listener;

    template<typename ...Args>
    int NotifyOfEvent(int device_type, int device_event, Args... args)
    {
        return device_event_listener(device_type, device_event, args...);
    }
}

extern "C"
{
UNITY_API void SetDeviceEventListener(device_events::DeviceEventListener *callback);
}


