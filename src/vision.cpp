//
// Created by Lucas on 2020-06-12.
//

#include "shared_robot_api.hpp"
#include "unity_api/hardware.h"

namespace shared_api
{
    Vision::Vision(int _port) : port(_port)
    {

    }

    int32_t Vision::set_led(const int32_t rgb)
    {
        return vision_led_change_callback(port, rgb);
    }
}
