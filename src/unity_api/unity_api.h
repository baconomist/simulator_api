#pragma once

#include <string>
#include <functional>
#include "shared_robot_api.hpp"

// Enable this to output the exception path as only ${PROJECT_DIR}/path rather than the abs path
const bool TRUNCATE_CONSOLE_EXCEPTION_PATH = true;
const std::string CPP_LOG_FILE = "C:\\Users\\Lucas\\Desktop\\Projects\\2020-4659-Vex\\CodeRepo\\RobotUnityProject\\Assets\\cpp_api_output.log";
const std::string CPP_PROJECT_PATH = "C:\\Users\\Lucas\\Desktop\\Projects\\2020-4659-Vex\\CodeRepo\\RobotCode";

namespace unity_api
{
    // 2x the actual motor limit of 8 if you wanna make a wacky bot
    const int MAX_MOTORS = 16;
    const int OUTPUT_BUFFER_SIZE = 99999;

    extern bool API_INITIALIZED;

    extern std::ofstream *log_file;

    extern std::string* output_buff;

    typedef void* (OutputBufferListener)();
    extern OutputBufferListener* log_info_listener;
    extern OutputBufferListener* log_debug_listener;
    extern OutputBufferListener* log_warn_listener;
    extern OutputBufferListener* log_err_listener;
    extern OutputBufferListener* log_except_listener;
}
