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

UNITY_API void SetLogInfoListener(void *(listener)())
{
    unity_api::UnityAPI::GetInstance()->log_info_listener = listener;
}

UNITY_API void SetLogDebugListener(void *(listener)())
{
    unity_api::UnityAPI::GetInstance()->log_debug_listener = listener;
}

UNITY_API void SetLogWarnListener(void *(listener)())
{
    unity_api::UnityAPI::GetInstance()->log_warn_listener = listener;
}

UNITY_API void SetLogErrListener(void *(listener)())
{
    unity_api::UnityAPI::GetInstance()->log_err_listener = listener;
}

UNITY_API void SetLogExceptListener(void *(listener)())
{
    unity_api::UnityAPI::GetInstance()->log_except_listener = listener;
}


UNITY_API void ReadOutputBuffer(char *outBuff)
{
    // Copy buffer data into unity outBuff
    std::string output_buff = unity_api::UnityAPI::GetInstance()->output_buff;
    strcpy_s(outBuff, OUTPUT_BUFFER_SIZE, output_buff.c_str());
    unity_api::UnityAPI::GetInstance()->output_buff = "";
}

UNITY_API void InitializeAutonomous()
{
    win_try
    {
        shared_api::initialize_autonomous();
    }
    win_catch(ExpFilter(GetExceptionInformation(), GetExceptionCode()))
    {}
}

UNITY_API void InitializeOpControl()
{
    win_try
    {
        shared_api::initialize_opcontrol();
    }
    win_catch(ExpFilter(GetExceptionInformation(), GetExceptionCode()))
    {}
}

UNITY_API void UpdateAutonomous()
{
    win_try
    {
        shared_api::update_autonomous();
    }
    win_catch(ExpFilter(GetExceptionInformation(), GetExceptionCode()))
    {}
}

UNITY_API void UpdateOpControl()
{
    win_try
    {
        shared_api::update_opcontrol();
    }
    win_catch(ExpFilter(GetExceptionInformation(), GetExceptionCode()))
    {}
}
}


