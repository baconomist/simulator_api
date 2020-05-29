//
// Created by Lucas on 2020-05-22.
//


#include "shared_robot_api.hpp"
#include "unity_api.h"

namespace shared_api
{
    void Motor::move_voltage(int _voltage)
    {
        voltage = _voltage;
    }

    Motor::Motor(int _port) : port(_port)
    {
        unity_api::UnityAPI::GetInstance()->RegisterMotor(this);
    }

    Motor::~Motor()
    {

    }
}
