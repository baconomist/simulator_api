//
// Created by Lucas on 2020-05-22.
//


#include "shared_robot_api.hpp"
#include "unity_api/hardware.h"

namespace shared_api
{
    Motor::Motor(int _port) : port(_port)
    {
    }

    void Motor::move_voltage(int _voltage)
    {
        voltage = _voltage;
        motor_voltage_change_callback(port, voltage);
    }

    Motor::~Motor() = default;
}
