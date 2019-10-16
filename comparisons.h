#pragma once

#include "shifts.h"
#include "sign.h"

// Note: Most compilers can generate faster code from standard idioms using
// comparison operators [! < = >] with optimizations on.

// Returns -1 if x is nonzero, and 0 if it is zero.
//
static inline int is_nonzero_0n1(const int x)
{
    return asr_max(int, x | (-x));
}

// Returns -1 if x is zero, and 0 if it is nonzero.
//
static inline int is_zero_0n1(const int x)
{
    return ~asr_max(int, x | (-x));
}

// Return 1 if the value is negative, 0 otherwise.
//
static inline int is_lt_0(int x)
{
    return lsr_max(int, x);
}

// Return 1 if the value is positive, 0 otherwise.
//
static inline int is_ge_0(int x)
{
    return is_lt_0(x) ^ 1;

    // Usually slower alternative:
    // return ~((sign_n101(x)) >> 1) & 1;
}

// Returns 1 if x is greater than 0, otherwise returns 0
//
static inline int is_gt_0(int x)
{
    return is_ge_0(x) & is_nonzero_0n1(x);
}
