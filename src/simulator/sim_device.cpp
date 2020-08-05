//
// Created by Lucas on 2020-06-13.
//

#include "simulator_globals.h"
#include "sim_device.h"
#include "device_registry.h"

namespace simulator
{
    SimDevice::SimDevice(shared_api::hardware::BrainPort port) : _port(port)
    {
        simulator::register_device(this);
    }

    SimDevice::SimDevice(int port) : _port(static_cast<shared_api::hardware::BrainPort>(port))
    {
        simulator::register_device(this);
    }

    shared_api::hardware::BrainPort SimDevice::getPort()
    {
        return _port;
    }
}
