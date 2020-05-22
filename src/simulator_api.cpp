//
// Created by Lucas on 2020-05-22.
//

#include "simulator_api.h"
#include "unity_api.h"

namespace shared_api
{
    void Motor::move_voltage(int _voltage)
    {
        voltage = _voltage;
    }

    Motor::Motor(int _port) : port(_port)
    {
        unity_api::SimRobotUnityAPI::GetInstance()->RegisterMotor(this);
    }

    Motor::~Motor()
    {

    }
}