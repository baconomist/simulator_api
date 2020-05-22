#pragma once

#include "shared_robot_api.hpp"

#define SIM_ROBOT_API __declspec(dllexport)

namespace unity_api
{
    // 2x the actual motor limit of 8 if you wanna make a wacky bot
    const int MAX_MOTORS = 16;

    class SimRobotUnityAPI
    {
        static SimRobotUnityAPI *instance;

        SimRobotUnityAPI();

    public:

        static SimRobotUnityAPI *GetInstance();

        float velocity = 0.0f;
        shared_api::Motor* motors[MAX_MOTORS];
        int added_motor_index = 0;

        void RegisterMotor(shared_api::Motor* motor);
        shared_api::Motor* GetMotor(int port);

        ~SimRobotUnityAPI();
    };
}
