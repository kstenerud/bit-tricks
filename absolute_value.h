#pragma once

#include "shifts.h"

// Gets the absolute value of x
//
static inline int absolute_value(int x)
{
    const int mask = asr_max(int, x);
    return (x + mask) ^ mask;
}
