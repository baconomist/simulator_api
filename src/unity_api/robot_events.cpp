//
// Created by Lucas on 2020-05-30.
//

#include "robot_events.h"
#include "exception_handling.h"

UNITY_API void RobotInitialize()
{
    win_try
    {
        shared_api::initialize();
    }
    win_catch(ExpFilter(GetExceptionInformation(), GetExceptionCode()))
    {}
}

UNITY_API void CompetitionInitialize()
{
    win_try
    {
        shared_api::competition_initialize();
    }
    win_catch(ExpFilter(GetExceptionInformation(), GetExceptionCode()))
    {}
}

UNITY_API void CompetitionDisable()
{
    win_try
    {
        shared_api::disabled();
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

UNITY_API void InitializeOpControl()
{
    win_try
    {
        shared_api::initialize_opcontrol();
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

UNITY_API void UpdateOpControl()
{
    win_try
    {
        shared_api::update_opcontrol();
    }
    win_catch(ExpFilter(GetExceptionInformation(), GetExceptionCode()))
    {}
}
