//
// Created by Lucas on 2020-06-12.
//

#include "shared_robot_api.hpp"
#include "unity_api/param_handler.h"

namespace shared_api::hardware
{
    Vision::Vision(BrainPort port) : BrainDevice(port)
    {
        ParamRegistry::RegisterWritableParameterStream<ParamType::Int, int>((int) port, "rgbColor");
    }

    int32_t Vision::set_led(const int32_t rgb)
    {
        ParamRegistry::WriteParameterStream<ParamType::Int, int>((int) port, "rgbColor", rgb);
        return 0;
    }
}
