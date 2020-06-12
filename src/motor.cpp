//
// Created by Lucas on 2020-05-22.
//


#include "shared_robot_api.hpp"
#include "unity_api/device_event_handler.h"

enum class DeviceEvent
{
    VoltageChange = 0
};

namespace shared_api
{
    Motor::Motor(int _port) : port(_port)
    {
    }

    void Motor::move_voltage(int _voltage)
    {
        voltage = _voltage;
        device_events::NotifyOfEvent<int>((int) device_events::DeviceType::Motor, (int) DeviceEvent::VoltageChange, 1);
    }

    Motor::~Motor() = default;
}
