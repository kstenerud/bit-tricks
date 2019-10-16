#pragma once

#include "comparisons.h"

// Gives the number of bytes required to store x bits.
//
static inline int get_bytes_required_for_bits(const int bits)
{
    const int extra_byte = is_nonzero_0n1(bits & 7) & 1;
    return (bits >> 3) + extra_byte;
}
