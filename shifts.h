#pragma once

#include <limits.h>

// Get the size of X in bits - 1
//
#define BITS_MAX(X) ( (sizeof(X) * CHAR_BIT - 1) )

// Logical shift left X by BITS
//
#define lsl(X, BITS) ( (X) << (BITS) )

// Logical shift right X by BITS, using the specified SIGNED_TYPE
//
#define lsr(SIGNED_TYPE, X, BITS) ( (unsigned SIGNED_TYPE)(X) >> (BITS) )

// Arithmetic shift right X by BITS, using the specified SIGNED_TYPE
//
#define asr(SIGNED_TYPE, X, BITS) ( -(int)lsr(SIGNED_TYPE, X, BITS) )


// Logical shift left by (size - 1)
//
#define lsl_max(X) lsl(X, BITS_MAX(X))

// Logical shift right by size - 1
//
#define lsr_max(SIGNED_TYPE, X) lsr(SIGNED_TYPE, X, BITS_MAX(SIGNED_TYPE))

// Arithmetic shift right by size - 1
//
#define asr_max(SIGNED_TYPE, X) ( -(int)lsr_max(SIGNED_TYPE, X) )


// Non-portable arithmetic shift right by size - 1
// Right shifts of signed integers is implementation-defined
//
#define asr_max_np(X) ((X) >> BITS_MAX(X))
