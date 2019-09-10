#pragma once

#include "is_ge_0.h"
#include "is_nonzero.h"

// Returns 1 if x is greater than 0, otherwise returns 0
//
static inline int is_gt_0(int x)
{
    return is_ge_0(x) & is_nonzero(x);
}
