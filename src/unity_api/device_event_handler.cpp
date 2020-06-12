//
// Created by Lucas on 2020-06-12.
//

#include <type_traits>
#include "unity_api.h"
#include "device_event_handler.h"


namespace device_events
{
    DeviceEventListener *device_event_listener;
}

UNITY_API void SetDeviceEventListener(device_events::DeviceEventListener *callback)
{
    device_events::device_event_listener = callback;
}
