//
// Created by Lucas on 2020-05-30.
//

#pragma once

#include "unity_api.h"
#include "unity_method_definitions.h"

typedef void *(MotorVoltageChangeCallback)(int motor_port, int voltage);

extern MotorVoltageChangeCallback *motor_voltage_change_callback;

typedef int (VisionLEDChangeCallback)(int vision_port, int32_t rgb);

extern VisionLEDChangeCallback *vision_led_change_callback;

extern "C"
{
UNITY_API int GetMaxMotors();
UNITY_API void SetMotorVoltageChangeCallback(MotorVoltageChangeCallback *callback);
UNITY_API void SetVisionLEDChangeCallback(VisionLEDChangeCallback *callback);
}