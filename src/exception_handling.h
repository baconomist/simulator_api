//
// Created by Lucas on 2020-05-29.
//

#pragma once

#include <string>
#include <windows.h>
#include "unity_api.h"
#include "StackWalker/StackWalker.h"

// Microsoft try and except functions that prevent unity from crashing, regular try/except will not work
#define win_try __try
#define win_catch __except

std::string error_code_to_message(unsigned int error_code);

// https://stackoverflow.com/questions/31639611/c-callstack-on-windows-access-violation
LONG WINAPI ExpFilter(EXCEPTION_POINTERS *pExp, unsigned int dwExpCode);

// https://www.codeproject.com/Articles/11132/Walking-the-callstack-2
class MyStackWalker : public StackWalker
{
public:
    MyStackWalker() : StackWalker()
    {}

protected:

    void OnCallstackEntry(CallstackEntryType eType, CallstackEntry &entry) override;
    void OnOutput(LPCSTR szText) override;
};