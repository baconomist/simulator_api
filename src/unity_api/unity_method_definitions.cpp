//
// Created by Lucas on 2020-05-22.
//

#include <iostream>
#include <fstream>
#include "shared_robot_api.hpp"
#include "unity_api.h"
#include "unity_method_definitions.h"
#include "exception_handling.h"
#include "testing/testing.h"

const int OUTPUT_BUFFER_SIZE = 99999;

static bool API_INITIALIZED = false;

std::ofstream *log_file = nullptr;

UNITY_API void InitializeAPI()
{
    log_file = new std::ofstream(CPP_LOG_FILE);
    // Redirect stdout and stdcerr to a file an output file
    std::cerr.rdbuf(log_file->rdbuf());
    std::cout.rdbuf(log_file->rdbuf());

    API_INITIALIZED = true;

    // Can't call shared_api::logging here since we might not have yet set the log listeners
    std::cout << "API INITIALIZED." << std::endl;
}

UNITY_API void DestroyAPI()
{
    shared_api::logging::info("Destroying API...");
    if (log_file != nullptr)
    {
        log_file->close();
        log_file = nullptr;
    }
    shared_api::logging::info("API Destroyed.");
}

UNITY_API int IsAPIInitialized()
{
    return API_INITIALIZED;
}

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

UNITY_API void RunAPITests()
{
    run_tests();
}


