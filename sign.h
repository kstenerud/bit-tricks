#pragma once

#include "shifts.h"

// Get the sign of an integer in the form:
// If x > 0, return 1
// If x = 0, return 0
// If x < 0, return -1
//
static inline int sign(int x)
{
    return asr_max(int, x) | (int)lsr_max(int, -x);
}
