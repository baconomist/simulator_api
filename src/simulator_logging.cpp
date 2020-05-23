//
// Created by Lucas on 2020-05-23.
//

#include "logging.h"
#include "unity_api.h"
#include <string>

namespace logging
{
    void add_to_simulated_buffer(const std::string& prefix, const std::string& message)
    {
        unity_api::SimRobotUnityAPI::GetInstance()->output_buff += prefix;
        unity_api::SimRobotUnityAPI::GetInstance()->output_buff += message;
        unity_api::SimRobotUnityAPI::GetInstance()->output_buff += "\n";
    }

    void info(const std::string& message)
    {
        add_to_simulated_buffer("[INFO]", message);
    }

    void debug(const std::string& message)
    {
        add_to_simulated_buffer("[DEBUG]", message);
    }

    void warn(const std::string& message)
    {
        add_to_simulated_buffer("[WARN]", message);
    }

    void error(const std::string& message)
    {
        add_to_simulated_buffer("[ERROR]", message);
    }
}