#pragma once

#include <limits.h>

// Get the maximum amount that a value or type can be shifted.
// This is the size of X in bits - 1, so for example, 7 for int8,
// 15 for int16, 31 for int32, etc.
//
#define MAX_SHIFT_COUNT(X) ( (sizeof(X) * CHAR_BIT - 1) )

// Logical shift left X by BITS
//
#define lsl(X, BITS) ( (X) << (BITS) )

// Logical shift right X by BITS, using the specified **unsigned** version of
// SIGNED_TYPE. It needs to cast to the unsigned type to make sure the compiler
// outputs LSR and not ASR.
//
#define lsr(SIGNED_TYPE, X, BITS) ( ((unsigned SIGNED_TYPE)(X)) >> (BITS) )

// Arithmetic shift right X by BITS, using the specified SIGNED_TYPE.
// This is technically implementation defined, but all major compilers output
// an ASR for this code.
//
#define asr(SIGNED_TYPE, X, BITS) ( ((SIGNED_TYPE)(X)) >> (BITS) )

// "Portable" version of asr. This causes most compilers to output extra instructions.
// Usually, it outputs an LSR and NEG, whereas a signed shift would only output an ASR.
//
#define asr_portable(SIGNED_TYPE, X, BITS) ( -(SIGNED_TYPE)lsr(SIGNED_TYPE, X, BITS) )


// Logical shift left by (size - 1)
//
#define lsl_max(X) lsl(X, MAX_SHIFT_COUNT(X))

// Logical shift right by size - 1
//
#define lsr_max(SIGNED_TYPE, X) lsr(SIGNED_TYPE, X, MAX_SHIFT_COUNT(SIGNED_TYPE))

// Arithmetic shift right by size - 1
//
#define asr_max(SIGNED_TYPE, X) asr(SIGNED_TYPE, X, MAX_SHIFT_COUNT(SIGNED_TYPE))
