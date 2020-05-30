//
// Created by Lucas on 2020-05-30.
//

#include "shared_robot_api.hpp"
#include "testing/testing.h"
#include "tests.h"
#include "exception_handling.h"

// Need this function since we can't unwind strings here
void _test_null_pointer(const std::string &test_name)
{
    win_try
    {
        int *a = nullptr;
        *a = 1;
    }
    win_catch(ExpFilter(GetExceptionInformation(), GetExceptionCode()))
    {
        log_test_succeeded(test_name);
    }
}

void test_null_pointer()
{
   _test_null_pointer("TEST_NULL_POINTER");
}