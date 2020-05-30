//
// Created by Lucas on 2020-05-22.
//

#pragma once

#define UNITY_API __declspec(dllexport)

extern "C"
{

UNITY_API void InitializeAPI();
UNITY_API void DestroyAPI();
UNITY_API int IsAPIInitialized();
UNITY_API void RunAPITests();

UNITY_API void SetLogInfoListener(void* (listener)());
UNITY_API void SetLogDebugListener(void* (listener)());
UNITY_API void SetLogWarnListener(void* (listener)());
UNITY_API void SetLogErrListener(void* (listener)());
UNITY_API void SetLogExceptListener(void* (listener)());

UNITY_API int GetOutputBufferSize();
UNITY_API void ReadOutputBuffer(char* outBuff);

UNITY_API void InitializeAutonomous();
UNITY_API void InitializeOpControl();
UNITY_API void UpdateAutonomous();
UNITY_API void UpdateOpControl();
}