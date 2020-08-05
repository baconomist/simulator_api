//
// Created by Lucas on 2020-08-04.
//

#include <map>

#include "device_registry.h"

namespace simulator
{
    std::map<int, SimDevice*> devices;

    void register_device(SimDevice* simDevice)
    {
        devices[(int) simDevice->getPort()] = simDevice;
    }

    void remove_device(shared_api::hardware::BrainPort port)
    {
        devices.erase((int) port);
    }
}