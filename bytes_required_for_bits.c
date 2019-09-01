// Gives the number of bytes required to store x bits.
//
// The trick is in calculating the remainder of (bits / 8), and then turning
// that into an addition of 0 or 1 to the byte count without branching.
//
static int get_bytes_required_for_bits(const int bits)
{
    // It's important that remainder is signed
    const char remainder = bits & 7;
    // ORing remainder with -remainder sets the high bit for any nonzero value.
    // Logical shift right by 7, and you have 0 for 0, 1 for anything else.
    const int extra_byte = ((remainder | (-remainder)) >> 7) & 1;
    return (bits >> 3) + extra_byte;
}
