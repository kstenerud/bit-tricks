#pragma once

#include "shifts.h"

// Returns -1 if x is nonzero, and 0 if it is zero.
//
static inline int is_nonzero(const int x)
{
    return asr_max(int, x | (-x));
}
