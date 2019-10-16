#pragma once

#include "shifts.h"

// Note: Most compilers can generate faster code from standard idioms:
//     return x > 0 ? x : -x

// Gets the absolute value of x
//
static inline int absolute_value(int x)
{
    const int mask = asr_max(int, x);
    return (x + mask) ^ mask;
}
