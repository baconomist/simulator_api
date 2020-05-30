#include <stdexcept>
#include "unity_api.h"
#include "unity_method_definitions.h"

namespace unity_api
{
    bool API_INITIALIZED = false;
    std::ofstream *log_file = nullptr;

    shared_api::Motor* motors[MAX_MOTORS];
    int added_motor_index;

    std::string* output_buff;

    OutputBufferListener* log_info_listener;
    OutputBufferListener* log_debug_listener;
    OutputBufferListener* log_warn_listener;
    OutputBufferListener* log_err_listener;
    OutputBufferListener* log_except_listener;

    void RegisterMotor(shared_api::Motor *motor)
    {
        if (added_motor_index >= MAX_MOTORS - 1)
            throw std::runtime_error("Cannot add more than MAX_MOTORS defined in unity_api.cpp");
        motors[added_motor_index] = motor;
        added_motor_index++;
    }

    shared_api::Motor *GetMotor(int port)
    {
        if (port >= MAX_MOTORS + 1)
            throw std::runtime_error("Cannot get more than MAX_MOTORS defined in unity_api.cpp");
        for (int i = 0; i < MAX_MOTORS; i++)
        {
            if (motors[i]->port == port)
                return motors[i];
        }
        return nullptr;
    }
}



