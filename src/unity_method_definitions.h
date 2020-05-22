//
// Created by Lucas on 2020-05-22.
//

#pragma once

#include "unity_api.h"

using namespace unity_api;

extern "C"
{
    namespace unity_api
    {
    SIM_ROBOT_API SimRobotUnityAPI *GetSharedRobotAPI();

    SIM_ROBOT_API void DeleteSharedRobotAPI(SimRobotUnityAPI *api);

    SIM_ROBOT_API int GetMotorVoltage(SimRobotUnityAPI *api, int port);

    SIM_ROBOT_API int Test();
    }
}