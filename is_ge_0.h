#pragma once

#include "sign.h"

// Returns 1 if x is greater than or equal to 0, otherwise returns 0
//
static inline int is_ge_0(int x)
{
    return ~((sign(x)) >> 1) & 1;
}
