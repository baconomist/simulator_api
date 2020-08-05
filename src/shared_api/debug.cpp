//
// Created by Lucas on 2020-08-04.
//

#include <intrin.h>
#include "simulator_globals.h"

// https://stackoverflow.com/questions/2389270/visual-studio-can-be-a-breakpoint-called-from-code
extern inline void shared_api::__debugbreakpoint()
{
    __debugbreak();
}