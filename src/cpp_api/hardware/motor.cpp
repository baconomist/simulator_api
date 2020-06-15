//
// Created by Lucas on 2020-05-22.
//


#include "shared_robot_api.hpp"
#include "unity_api/param_handler.h"

namespace shared_api::hardware
{
    Motor::Motor(BrainPort port) : BrainDevice(port)
    {
        ParamRegistry::RegisterReadonlyParameterStream<ParamType::Int, int>((int) port, "voltage", &voltage);
    }

    void Motor::move_voltage(int _voltage)
    {
        voltage = _voltage;
    }

    Motor::~Motor() = default;
}
