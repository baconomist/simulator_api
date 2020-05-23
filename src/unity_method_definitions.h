//
// Created by Lucas on 2020-05-22.
//

#pragma once

//#include "unity_api.h"
//
//using namespace unity_api;

#define SIM_ROBOT_API __declspec(dllexport)

extern "C"
{

SIM_ROBOT_API int Test();

//SIM_ROBOT_API SimRobotUnityAPI *GetSharedRobotAPI();
//
//SIM_ROBOT_API void DeleteSharedRobotAPI(SimRobotUnityAPI *api);
//
//SIM_ROBOT_API int GetMotorVoltage(SimRobotUnityAPI *api, int port);

SIM_ROBOT_API int GetOutputBufferSize();

SIM_ROBOT_API void ReadOutputBuffer(char* outBuff);

SIM_ROBOT_API void InitializeAutonomous();

SIM_ROBOT_API void InitializeOpControl();

SIM_ROBOT_API void UpdateAutonomous();

SIM_ROBOT_API void UpdateOpControl();

}