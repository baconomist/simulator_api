//
// Created by Lucas on 2020-05-22.
//

#pragma once

//#include "unity_api.h"
//
//using namespace unity_api;

#define UNITY_API __declspec(dllexport)

extern "C"
{

UNITY_API int Test();

//SIM_ROBOT_API SimRobotUnityAPI *GetSharedRobotAPI();
//
//SIM_ROBOT_API void DeleteSharedRobotAPI(SimRobotUnityAPI *api);
//
//SIM_ROBOT_API int GetMotorVoltage(SimRobotUnityAPI *api, int port);

UNITY_API int GetOutputBufferSize();

UNITY_API void ReadOutputBuffer(char* outBuff);

UNITY_API void InitializeAutonomous();

UNITY_API void InitializeOpControl();

UNITY_API void UpdateAutonomous();

UNITY_API void UpdateOpControl();

}