#include <stdexcept>
#include "unity_api.h"
#include "unity_method_definitions.h"

namespace unity_api
{
    bool API_INITIALIZED = false;
    std::ofstream *log_file = nullptr;

    std::string *output_buff;

    OutputBufferListener *log_info_listener;
    OutputBufferListener *log_debug_listener;
    OutputBufferListener *log_warn_listener;
    OutputBufferListener *log_err_listener;
    OutputBufferListener *log_except_listener;
}



