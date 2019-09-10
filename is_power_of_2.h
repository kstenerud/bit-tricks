#pragma once

#include "is_gt_0.h"
#include "is_zero.h"

// Returns 1 if x is a power of 2
//
static inline int is_power_of_2(int x)
{
    return is_gt_0(x) & is_zero(x & (x - 1));
}
