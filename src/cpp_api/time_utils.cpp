//
// Created by Lucas on 2020-05-30.
//

#include <chrono>
#include <thread>
#include "shared_robot_api.hpp"

namespace shared_api::time_utils
{
    void delay(const unsigned int millis)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(millis));
    }
}

