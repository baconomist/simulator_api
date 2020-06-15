//
// Created by Lucas on 2020-06-14.
//

#pragma once

#include <map>
#include <any>
#include "shared_robot_api.hpp"

enum class ParamType
{
    Undefined,
    Int,
    Float
};

struct Param
{
    ParamType paramType;
    // ValueData * (Pointer to param value)
    std::any value;
};

class ParamRegistry
{
private:
    // <DevicePort, <ParamName, Param struct>>
    static std::map<int, std::map<std::string, Param>> deviceParameterMap;

public:
    template<ParamType PT, typename T>
    static void RegisterParameter(int devicePort, const std::string &paramName, T *param)
    {
        if (isupper(paramName[0]))
            shared_api::logging::warn(
                    "WARNING: try to use C# public field naming conventions. Port: " + std::to_string(devicePort) +
                    " Param: " + paramName);
        deviceParameterMap[devicePort][paramName] = Param{PT, param};
    }

    template<typename T>
    static T GetParameter(int devicePort, const std::string &paramName)
    {
        if (ErrorCheck(devicePort, paramName)) return 0;

        Param param = deviceParameterMap[devicePort][paramName];
        return *std::any_cast<T *>(param.value);
    }

    static ParamType GetParameterType(int devicePort, const std::string &paramName);

    static int ErrorCheck(int devicePort, const std::string &paramName);
};
