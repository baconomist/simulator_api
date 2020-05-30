//
// Created by Lucas on 2020-05-30.
//

#include <functional>
#include "shared_robot_api.hpp"
#include "testing.h"
#include "tests/tests.h"

void run_tests()
{
    test_null_pointer();
}

void log_test_succeeded(const std::string& test_name)
{
    shared_api::logging::info("Test: <" + test_name + "> Passed.");
}