//
// Created by Lucas on 2020-08-04.
//

#include <unity_api/param_registry.h>
#include "devices.h"

namespace simulator
{
    SimMotor::SimMotor(int port) : SimDevice(port)
    {
        ParamRegistry::RegisterReadonlyParameterStream<ParamType::Int, int>((int) port, "voltage", &voltage);
    }
}