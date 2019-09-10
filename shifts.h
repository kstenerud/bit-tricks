#pragma once

#include <limits.h>

// Logical shift left by size - 1
//
#define lsl_max(X) ((X) << (sizeof(X) * CHAR_BIT - 1))

// Logical shift right by size - 1
//
#define lsr_max(SIGNED_TYPE, X) ((unsigned SIGNED_TYPE)(X) >> (sizeof(unsigned SIGNED_TYPE) * CHAR_BIT - 1))

// Arithmetic shift right by size - 1
//
#define asr_max(SIGNED_TYPE, X) ( -(int)lsr_max(SIGNED_TYPE, X) )


// Non-portable arithmetic shift right by size - 1
// Right shifts of signed integers is implementation-defined
//
#define asr_max_np(X) ((X) >> (sizeof(X) * CHAR_BIT - 1))
