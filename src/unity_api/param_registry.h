//
// Created by Lucas on 2020-06-14.
//

#pragma once

#include <map>
#include <any>
#include "simulator_globals.h"

enum class ParamType
{
    Undefined,
    Int,
    Float
};

struct ParamStream
{
    ParamType paramType;
    std::any value;
    // if true, value is a ParamType* pointer, otherwise value is just its "ParamType"
    bool isValueReadonlyPtr;
};

class ParamRegistry
{
private:
    // <DevicePort, <ParamName, Param struct>>
    static std::map<int, std::map<std::string, ParamStream>> deviceParameterMap;

public:
    template<ParamType PT, typename T>
    static void RegisterReadonlyParameterStream(int devicePort, const std::string &paramName, T *param)
    {
        deviceParameterMap[devicePort][paramName] = ParamStream{PT, param, true};
    }

    template<ParamType PT, typename T>
    static void RegisterWritableParameterStream(int devicePort, const std::string &paramName)
    {
        deviceParameterMap[devicePort][paramName] = ParamStream{PT, 0, false};
    }

    template<ParamType PT, typename T>
    static T ReadParameterStream(int devicePort, const std::string &paramName)
    {
        if (ErrorCheck(devicePort, paramName)) return 0;

        ParamStream paramStream = deviceParameterMap[devicePort][paramName];

        if (paramStream.isValueReadonlyPtr)
            return *std::any_cast<T*>(paramStream.value);
        else
            return std::any_cast<T>(paramStream.value);
    }

    template<ParamType PT, typename T>
    static void WriteParameterStream(int devicePort, const std::string &paramName, T value)
    {
        if (ErrorCheck(devicePort, paramName)) return;

        ParamStream paramStream = deviceParameterMap[devicePort][paramName];
        if (paramStream.isValueReadonlyPtr)
        {
            shared_api::logging::error(
                    "ParamStream is readonly! Cannot write to port: " + std::to_string(devicePort) + " paramName: " +
                    paramName);
        }

        paramStream.value = value;

        deviceParameterMap[devicePort][paramName] = paramStream;
    }

    static ParamType GetParameterType(int devicePort, const std::string &paramName);

    static int ErrorCheck(int devicePort, const std::string &paramName);
};
