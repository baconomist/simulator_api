//
// Created by Lucas on 2020-05-30.
//

#include "simulator_globals.h"
#include "robot_events.h"
#include "utils/exception_handling.h"

UNITY_API void Initialize()
{
    win_try
    {
        initialize();
    }
    win_catch(ExpFilter(GetExceptionInformation(), GetExceptionCode()))
    {}
}

UNITY_API void CompetitionInitialize()
{
    win_try
    {
        competition_initialize();
    }
    win_catch(ExpFilter(GetExceptionInformation(), GetExceptionCode()))
    {}
}

UNITY_API void CompetitionDisable()
{
    win_try
    {
        disabled();
    }
    win_catch(ExpFilter(GetExceptionInformation(), GetExceptionCode()))
    {}
}

UNITY_API void InitializeAutonomous()
{
    win_try
    {
        shared_api::initialize_autonomous();
    }
    win_catch(ExpFilter(GetExceptionInformation(), GetExceptionCode()))
    {}
}

UNITY_API void UpdateAutonomous()
{
    win_try
    {
        shared_api::update_autonomous();
    }
    win_catch(ExpFilter(GetExceptionInformation(), GetExceptionCode()))
    {}
}

UNITY_API void InitializeOpControl()
{
    win_try
    {
        shared_api::initialize_opcontrol();
    }
    win_catch(ExpFilter(GetExceptionInformation(), GetExceptionCode()))
    {}
}

UNITY_API void UpdateOpControl()
{
    win_try
    {
        shared_api::update_opcontrol();
    }
    win_catch(ExpFilter(GetExceptionInformation(), GetExceptionCode()))
    {}
}

