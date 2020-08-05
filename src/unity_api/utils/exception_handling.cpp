//
// Created by Lucas on 2020-05-30.
//

#include <Windows.h>
#include <iostream>

#include "simulator_globals.h"
#include "exception_handling.h"

unsigned int LAST_ERROR_CODE;

std::string error_code_to_message(unsigned int error_code)
{
    std::string msg;

    // TODO: make this more comprehensive
    switch (error_code)
    {
        case EXCEPTION_ACCESS_VIOLATION:
            msg = "Null Pointer Exception";
            break;
        case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
            msg = "Array Index Out Of Range";
            break;
        case EXCEPTION_INT_DIVIDE_BY_ZERO:
            msg = "Division By Zero";
            break;
        case EXCEPTION_FLT_DIVIDE_BY_ZERO:
            msg = "Division By Zero";
            break;
        case EXCEPTION_STACK_OVERFLOW:
            msg = "Stack Overflow";
            break;
        default:
            msg = "C++ HANDLE NOT IMPLEMENTED FOR THIS ERROR";
            break;
    }

    return msg;
}

LONG WINAPI ExpFilter(EXCEPTION_POINTERS *pExp, unsigned int dwExpCode)
{
    std::cout << "LAST_ERROR_CODE: " << LAST_ERROR_CODE << std::endl;

    LAST_ERROR_CODE = dwExpCode;

    // TODO: Is creating a new instance like this ok?
    MyStackWalker stackWalker;
    stackWalker.ShowCallstack(pExp, pExp->ContextRecord);

    return EXCEPTION_EXECUTE_HANDLER;
    // THIS CRASHES UNITY!!!!!!
    // return EXCEPTION_CONTINUE_EXECUTION;
}

void MyStackWalker::OnCallstackEntry(CallstackEntryType eType, CallstackEntry &entry)
{
    if (eType == CallstackEntryType::firstEntry)
    {
        std::string error_msg = error_code_to_message(LAST_ERROR_CODE);
        std::string path = entry.lineFileName;

        if (TRUNCATE_CONSOLE_EXCEPTION_PATH)
        {
            // + 1 to remove leading "\"
            path = path.substr(CPP_PROJECT_PATH.size() + 1, path.length());
        }

        shared_api::logging::error(error_msg
                                   + " in " + path + " at " + entry.name + " on line: " +
                                   std::to_string(entry
                                                          .lineNumber));
    }

    StackWalker::OnCallstackEntry(eType, entry
    );
}


void MyStackWalker::OnOutput(LPCSTR szText)
{
    std::string str(szText);
    std::string lower_szText;
    for (char i : str)
        lower_szText += ::tolower(i);

    std::string lower_project_path;
    for (char i : CPP_PROJECT_PATH)
        lower_project_path += ::tolower(i);

    // Let's only log the CPP errors from our project and not millions of Windows stack trace
    if (lower_szText.find(lower_project_path) != std::string::npos &&
        lower_szText.find(".dll") == std::string::npos || lower_szText.find("lasterror") != std::string::npos)
    {
        std::cerr << lower_szText << std::endl;
    }

    StackWalker::OnOutput(szText);
}
