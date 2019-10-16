#pragma once

#include "bitsize.h"
#include "shifts.h"
#include "difference.h"

// Note: Most compilers can generate faster code from standard idioms using
// comparison operators [! < = >] with optimizations on.


// Get the sign of an integer in the form:
// If x > 0, return 1
// If x = 0, return 0
// If x < 0, return -1
//
static inline int sign_n101(int x)
{
    return asr_max(int, x) | (int)lsr_max(int, -x);
}

// Get the sign of an integer in the form:
// If x >= 0, return 1
// If x < 0, return -1
//
static inline int sign_n11(int x)
{
    return sign_n101(x) | 1;
}

// Get the sign of an integer in the form:
// If x >= 0, return 0
// If x < 0, return 1
//
static inline int sign_01(int x)
{
    return asr_max(int, x) & 1;
}

// Returns 1 if the signs of the operands are different, 0 if they are the same.
//
static inline int signs_are_different(int x, int y)
{
    int diff = differing_bits(x, y);
    return asr_max(int, diff) & 1;
}

// Sign extends the operand based on the specified bit position.
// Calling with from_bit_pos == 0 is undefined.
//
static inline int sign_extend(int x, unsigned from_bit_pos)
{
    int shift_amount = bitsizeof(x) - from_bit_pos;
    return ( (int)((unsigned)x << shift_amount) >> shift_amount );
}
