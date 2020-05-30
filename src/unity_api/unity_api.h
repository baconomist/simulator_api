#pragma once

#include "shared_robot_api.hpp"
#include <string>

// Enable this to output the exception path as only ${PROJECT_DIR}/path rather than the abs path
const bool TRUNCATE_CONSOLE_EXCEPTION_PATH = true;
const std::string CPP_LOG_FILE = "C:\\Users\\Lucas\\Desktop\\Projects\\2020-4659-Vex\\CodeRepo\\RobotUnityProject\\Assets\\cpp_api_output.log";
const std::string CPP_PROJECT_PATH = "C:\\Users\\Lucas\\Desktop\\Projects\\2020-4659-Vex\\CodeRepo\\RobotCode";

namespace unity_api
{
    // 2x the actual motor limit of 8 if you wanna make a wacky bot
    const int MAX_MOTORS = 16;

    class UnityAPI
    {
        static UnityAPI *instance;

        UnityAPI();

    public:
        static UnityAPI *GetInstance();

        float velocity = 0.0f;
        shared_api::Motor* motors[MAX_MOTORS];
        int added_motor_index = 0;
        std::string output_buff = "";

        typedef void* (OutputBufferListener)();
        OutputBufferListener* log_info_listener;
        OutputBufferListener* log_debug_listener;
        OutputBufferListener* log_warn_listener;
        OutputBufferListener* log_err_listener;
        OutputBufferListener* log_except_listener;

        void RegisterMotor(shared_api::Motor* motor);
        shared_api::Motor* GetMotor(int port);

        ~UnityAPI();
    };
}
