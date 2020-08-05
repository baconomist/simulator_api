//
// Created by Lucas on 2020-08-04.
//

#pragma once

#include "simulator_globals.h"

namespace simulator
{
    class SimDevice
    {
    protected:
        shared_api::hardware::BrainPort _port;

    public:
        explicit SimDevice() = default;

        explicit SimDevice(shared_api::hardware::BrainPort _port);

        explicit SimDevice(int _port);

        shared_api::hardware::BrainPort getPort();

        virtual ~SimDevice() = default;
    };
}
