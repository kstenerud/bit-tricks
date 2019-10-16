#pragma once

// Returns 1 in each bit position where A and B had different values.
//
#define differing_bits(A, B) ( (A) ^ (B) )
