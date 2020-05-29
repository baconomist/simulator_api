//
// Created by Lucas on 2020-05-22.
//

#include "shared_robot_api.hpp"
#include "unity_api.h"
#include "unity_method_definitions.h"
#include <string>

const int OUTPUT_BUFFER_SIZE = 9999;

UNITY_API int Test()
{
    return 232323;
}

//SIM_ROBOT_API SimRobotUnityAPI *GetSharedRobotAPI()
//{
//    return SimRobotUnityAPI::GetInstance();
//}
//
//SIM_ROBOT_API void DeleteSharedRobotAPI(SimRobotUnityAPI *api)
//{
//    delete api;
//}
//
//SIM_ROBOT_API int GetMotorVoltage(SimRobotUnityAPI *api, int port)
//{
//    return api->GetMotor(port)->voltage;
//}

UNITY_API int GetOutputBufferSize()
{
    return OUTPUT_BUFFER_SIZE;
}

UNITY_API void ReadOutputBuffer(char* outBuff)
{
    std::string output_buff = unity_api::UnityAPI::GetInstance()->output_buff;
    strcpy_s(outBuff, OUTPUT_BUFFER_SIZE, output_buff.c_str());
    unity_api::UnityAPI::GetInstance()->output_buff = "";
}

UNITY_API void InitializeAutonomous()
{
    shared_api::initialize_autonomous();
}

UNITY_API void InitializeOpControl()
{
    shared_api::initialize_opcontrol();
}

UNITY_API void UpdateAutonomous()
{
    shared_api::update_autonomous();
}

UNITY_API void UpdateOpControl()
{
    shared_api::initialize_opcontrol();
}


