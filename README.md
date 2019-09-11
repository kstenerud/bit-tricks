Bit Tricks
==========

Various tricks for dealing with bits.

Most of these are useless in modern compilers because they already detect common comparison idioms (`if(x) return y`) and emit nonbranching code. Many of these tricks are slower than idiomatic code as a result.

Try comparing them with their `if()` equivalents in https://godbolt.org with optimizations on (`-O3` for gcc/clang, `/O2` for MSVC) and see for yourself (remember to omit the `static inline` prefixes or else godbolt won't show the result).


Optimizing Compilers
--------------------

Generally, compilers are good at optimizing away idiomatic conditional jumps for up to two comparison operations. With three it gets iffy, depending on the compiler and platform. GCC, CLANG, and Intel can often handle 3 operations, but MSVC has trouble on ARM (MSVC generally produces worse ARM code than GCC and CLANG).

### The Strange Case of Bitwise Operators

All compilers seem to produce better code when using bitwise operators (`&` and `|`) rather than conditional operators (`&&` and `||`) to join comparison operations. [This can be verified using the following code](https://godbolt.org/z/AGktLm):

```c
int is_power_of_2_conditional(int x)
{
    // Produces a conditional jump
    return (x > 0) && ((x & (x - 1)) == 0);
}

int is_power_of_2_bitwise(int x)
{
    // Does not produce a conditional jump
    return (x > 0) & ((x & (x - 1)) == 0);
}
```
