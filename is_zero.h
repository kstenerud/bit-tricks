#pragma once

#include "shifts.h"

// Returns -1 if x is zero, and 0 if it is nonzero.
//
static inline int is_zero(const int x)
{
    return ~asr_max(int, x | (-x));
}
