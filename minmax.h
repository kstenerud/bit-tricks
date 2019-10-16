#pragma once

#include "shifts.h"

// Note: Most compilers can generate faster code from standard idioms:
//     return x > y ? x : y


// Returns the minimum of two integers
//
static inline int min_int(int x, int y)
{
    int diff = x - y;
    return y + (diff & asr_max(int, diff));
}

// Returns the maximum of two integers
//
static inline int max_int(int x, int y)
{
    int diff = x - y;
    return x - (diff & asr_max(int, diff));
}
