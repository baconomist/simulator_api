//
// Created by Lucas on 2020-05-23.
//

#include <string>
#include <iostream>
#include "logging.h"
#include "unity_api/unity_api.h"

namespace shared_api::logging
{
    void log_to_simulated_buffer(const std::string& prefix, const std::string& message)
    {
        *unity_api::output_buff += prefix;
        *unity_api::output_buff += " ";
        *unity_api::output_buff += message;
        *unity_api::output_buff += "\n";
    }

    void log_to_file(const std::string& prefix, const std::string& message)
    {
        std::cout << prefix << " " << message << std::endl;
    }

    void info(const std::string& message)
    {
        log_to_file("[INFO]", message);
        log_to_simulated_buffer("[INFO]", message);
        // Call unity listener to inform it of a logging action
        unity_api::log_info_listener();
    }

    void debug(const std::string& message)
    {
        log_to_file("[DEBUG]", message);
        log_to_simulated_buffer("[DEBUG]", message);
        unity_api::log_debug_listener();
    }

    void warn(const std::string& message)
    {
        log_to_file("[WARN]", message);
        log_to_simulated_buffer("[WARN]", message);
        unity_api::log_warn_listener();
    }

    void error(const std::string& message)
    {
        log_to_file("[ERROR]", message);
        log_to_simulated_buffer("[ERROR]", message);
        unity_api::log_err_listener();
    }

    void exception(const std::exception &e)
    {
        log_to_file("[EXCEPTION]", e.what());
        log_to_simulated_buffer("[EXCEPTION]", e.what());
        unity_api::log_except_listener();
    }
}