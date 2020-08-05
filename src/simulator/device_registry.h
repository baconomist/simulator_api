//
// Created by Lucas on 2020-08-04.
//

#pragma once

#include <map>
#include "simulator_globals.h"
#include "sim_device.h"

namespace simulator
{
    extern std::map<int, SimDevice*> devices;

//    template<typename T>
//    T& register_device(shared_api::hardware::BrainPort port)
//    {
//        devices[(int) port] = new T();
//        return devices[(int) port];
//    }

    void register_device(SimDevice* simDevice);

    template<typename T>
    T* get_device(shared_api::hardware::BrainPort port)
    {
        return get_device<T>((int) port);
    }

    template<typename T>
    T* get_device(int port)
    {
        return static_cast<T*>(devices.at(port));
    }
}