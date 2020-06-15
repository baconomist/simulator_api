//
// Created by Lucas on 2020-05-22.
//

#include <iostream>
#include <fstream>
#include "shared_robot_api.hpp"
#include "unity_api.h"
#include "api_methods.h"
#include "testing/testing.h"

using namespace unity_api;

UNITY_API void InitializeAPI()
{
    output_buff = new std::string();
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
    log_info_listener = listener;
}

UNITY_API void SetLogDebugListener(void *(listener)())
{
    log_debug_listener = listener;
}

UNITY_API void SetLogWarnListener(void *(listener)())
{
    log_warn_listener = listener;
}

UNITY_API void SetLogErrListener(void *(listener)())
{
    log_err_listener = listener;
}

UNITY_API void SetLogExceptListener(void *(listener)())
{
    log_except_listener = listener;
}


UNITY_API void ReadOutputBuffer(char *outBuff)
{
    // Copy buffer data into Unity outBuff
    std::string out_buff = *output_buff;
    strcpy_s(outBuff, OUTPUT_BUFFER_SIZE, out_buff.c_str());
    // Clear output_buff
    *output_buff = "";
}

UNITY_API void RunAPITests()
{
    run_tests();
}


