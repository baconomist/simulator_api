//
// Created by Lucas on 2020-05-30.
//

#pragma once

#include <map>
#include <any>
#include "unity_api.h"
#include "api_methods.h"
#include "shared_robot_api.hpp"
#include "param_registry.h"

// !IMPORTANT All uris should start with a leading slash(/...)
static const std::string paramUriRoot = "/<Brain>";

// TODO: Maybe split into 2 separate objects where one of them simply is a "return" value for a parameter,
// IE: struct ParamRequest{char paramUri[1024], char msg[1024]}
// IE: struct ParamResponse{int int_val, float float_val};
struct ParamRequestResponse
{
    char paramUri[1024];
    char msg[1024];
    int int_val;
    float float_val;
};

typedef void (UnityParamRequestListener)(ParamRequestResponse paramRequest);

extern UnityParamRequestListener *unityParamRequestListener;

ParamRequestResponse CreateParamRequestResponse(shared_api::hardware::BrainPort port, const std::string &deviceType,
                                                const std::string &paramName, const std::string &msg = "",
                                                int int_val = 0,
                                                float float_val = 0);

extern "C"
{
UNITY_API void SetParamRequestListener(UnityParamRequestListener *paramRequestListener);
UNITY_API void RequestParam(ParamRequestResponse &paramRequestResponse);
UNITY_API ParamRequestResponse CreateParamRequestResponse(int port, const char *deviceType,
                                                          const char *paramName, const char *msg = "",
                                                          int int_val = 0,
                                                          float float_val = 0);
}