//
// Created by Lucas on 2020-05-30.
//

#pragma once

#include "api_methods.h"

extern "C"
{
    UNITY_API void RobotInitialize();
    UNITY_API void CompetitionInitialize();
    UNITY_API void CompetitionDisable();
    UNITY_API void InitializeAutonomous();
    UNITY_API void InitializeOpControl();
    UNITY_API void UpdateAutonomous();
    UNITY_API void UpdateOpControl();
}