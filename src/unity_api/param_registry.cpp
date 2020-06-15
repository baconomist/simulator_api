//
// Created by Lucas on 2020-06-14.
//

#include "param_registry.h"

std::map<int, std::map<std::string, ParamStream>> ParamRegistry::deviceParameterMap;

ParamType ParamRegistry::GetParameterType(int devicePort, const std::string& paramName)
{
    if (ParamRegistry::ErrorCheck(devicePort, paramName)) return ParamType::Undefined;

    ParamStream param = deviceParameterMap[devicePort][paramName];
    return param.paramType;
}

int ParamRegistry::ErrorCheck(int devicePort, const std::string &paramName)
{
    if (isupper(paramName[0]))
        shared_api::logging::warn(
                "WARNING: try to use C# public field naming conventions. Port: " + std::to_string(devicePort) +
                " Param: " + paramName);

    if (deviceParameterMap.find(devicePort) == deviceParameterMap.end())
    {
        shared_api::logging::error("Device not registered to port: " + std::to_string(devicePort));
        return 1;
    }

    if (deviceParameterMap.find(devicePort)->second.find(paramName) == deviceParameterMap.find(devicePort)->second.end())
    {
        shared_api::logging::error(
                "Param not registered to port: " + std::to_string(devicePort) + " and paramName: " + paramName);
        return 1;
    }

    return 0;
}
