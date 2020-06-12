//
// Created by Lucas on 2020-06-12.
//

#include "shared_robot_api.hpp"
#include "unity_api/hardware.h"
#include "unity_api/device_event_handler.h"

enum class DeviceEvent
{
    LEDChange
};

namespace shared_api
{
    Vision::Vision(int _port) : port(_port)
    {

    }

    int32_t Vision::set_led(const int32_t rgb)
    {
        return device_events::NotifyOfEvent<int, float>((int) device_events::DeviceType::VisionSensor, (int) DeviceEvent::LEDChange, 1, 20);
    }
}
