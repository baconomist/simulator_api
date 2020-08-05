//
// Created by Lucas on 2020-08-04.
//

#include <simulator/sim_device.h>

namespace simulator
{
    class SimMotor : public SimDevice
    {
    public:
        int voltage = 0;

        explicit SimMotor(int port);
    };
}