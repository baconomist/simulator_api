//
// Created by Lucas on 2020-05-30.
//

#include <hardware/hardware.h>
#include <cctype>

#include "unity_api.h"
#include "param_handler.h"

using namespace unity_api;

bool is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

std::string get_param_name(const std::string &paramUriStr)
{
    std::string paramName;
    // ?paramName=...&deviceType=
    if (paramUriStr.find("paramName=") < paramUriStr.find("deviceType="))
    {
        paramName = paramUriStr.substr(paramUriStr.find("paramName=") + std::string("paramName=").length(),
                                       paramUriStr.find("deviceType=") -
                                       (paramUriStr.find("paramName=") + std::string("paramName=").length()) - 1);
    } else // ?deviceType=...&paramName=
    {
        shared_api::logging::error("Param Uri Formatting Problem, Not Implemented...");
    }

    return paramName;
}

std::string get_device_type(const std::string &paramUriStr)
{
    std::string deviceType;

    // ?paramName=...&deviceType=
    if (paramUriStr.find("paramName=") < paramUriStr.find("deviceType="))
    {
        deviceType = paramUriStr.substr(paramUriStr.find("deviceType=") + std::string("deviceType=").length(),
                                        paramUriStr.length() - paramUriStr.find("deviceType="));
    } else // ?deviceType=...&paramName=
    {
        shared_api::logging::error("Param Uri Formatting Problem, Not Implemented...");
    }

    return deviceType;
}

std::string get_port(const std::string &paramUriStr)
{
    return paramUriStr.substr(paramUriStr.find(paramUriRoot) + paramUriRoot.length() + 1,
                              paramUriStr.find('?') -
                              (paramUriStr.find(paramUriRoot) + paramUriRoot.length() + 1));
}

UnityParamRequestListener *unityParamRequestListener;

ParamRequestResponse CreateParamRequestResponse(shared_api::hardware::BrainPort port,
                                                const std::string &deviceType, const std::string &paramName,
                                                const std::string &msg, int int_val, float float_val)
{
    return CreateParamRequestResponse((int) port, deviceType.c_str(), paramName.c_str(), msg.c_str(), int_val,
                                      float_val);
}

UNITY_API void SetParamRequestListener(UnityParamRequestListener *paramRequestListener)
{
    unityParamRequestListener = paramRequestListener;
}

// TODO: add error checking
UNITY_API void RequestParam(ParamRequestResponse &paramRequestResponse)
{
    std::string paramUriStr = paramRequestResponse.paramUri;
    std::string port = get_port(paramUriStr);
    std::string paramName = get_param_name(paramUriStr);
    std::string deviceType = get_device_type(paramUriStr);

    // TODO: check device type
    if (is_number(port))
    {
        switch (ParamRegistry::GetParameterType(std::stoi(port), paramName))
        {
            case ParamType::Undefined:
                shared_api::logging::error(
                        "Parameter type incorrect or undefined. paramName: " + paramName + " deviceType: " +
                        deviceType);
                break;
            case ParamType::Int:
                paramRequestResponse.int_val = ParamRegistry::ReadParameterStream<ParamType::Int, int>(std::stoi(port), paramName);
                break;
            case ParamType::Float:
                paramRequestResponse.float_val = ParamRegistry::ReadParameterStream<ParamType::Float, float>(std::stoi(port), paramName);
                break;
        }
    }
}

UNITY_API ParamRequestResponse CreateParamRequestResponse(int port, const char *deviceType,
                                                          const char *paramName, const char *msg,
                                                          int int_val,
                                                          float float_val)
{
    std::string port_str = std::to_string(port);
    std::string paramUri =
            std::string(paramUriRoot) + "/" + std::to_string(port) + "?paramName=" + std::string(paramName) +
            "&deviceType=" +
            std::string(deviceType);

    ParamRequestResponse paramRequestResponse{};
    strcpy_s(paramRequestResponse.paramUri, paramUri.c_str());
    strcpy_s(paramRequestResponse.msg, msg);
    paramRequestResponse.int_val = int_val;
    paramRequestResponse.float_val = float_val;

    return paramRequestResponse;
}
