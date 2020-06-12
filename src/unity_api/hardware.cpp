//
// Created by Lucas on 2020-05-30.
//

#include "unity_api.h"
#include "hardware.h"

using namespace unity_api;

MotorVoltageChangeCallback* motor_voltage_change_callback;
VisionLEDChangeCallback* vision_led_change_callback;

UNITY_API int GetMaxMotors()
{
    return MAX_MOTORS;
}

UNITY_API void SetMotorVoltageChangeCallback(MotorVoltageChangeCallback* callback)
{
    motor_voltage_change_callback = callback;
}

UNITY_API void SetVisionLEDChangeCallback(VisionLEDChangeCallback *callback)
{
    vision_led_change_callback = callback;
}