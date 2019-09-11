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


Other Tidbits
-------------

### Signed Shifts

There seems to be [a](https://stackoverflow.com/questions/7522346/right-shift-and-signed-integer) [lot](https://stackoverflow.com/questions/7622/are-the-shift-operators-arithmetic-or-logical-in-c) [of](https://en.wikipedia.org/wiki/Bitwise_operation#cite_ref-3) [flap](http://www.cplusplus.com/forum/beginner/251301/) over right shifts (`>>`) on signed integers. It comes down to this part of the C11 standard (section 6.5, paragraph 4):

*"Some operators (the unary operator ~ , and the binary operators <<, >>, &, ^, and |, collectively described as bitwise operators) shall have operands that have integral type. These operators return values that depend on the internal representations of integers, and thus have implementation-defined and undefined aspects for signed types."*

**In other words:** Because it's technically possible for an implementation to represent signed integers in a format other than two's complement, these operations are officially "implementation defined" (because there's no way to predict how CPU XYZ's custom signed integer implementation would be affected by bit shifts). But since all modern systems use two's complement for signed integers, they also all do arithmetic shifts for signed integers. So this is a relic from the past that can be ignored except in the most esoteric or ancient of systems.

We can confirm this on [godbolt](https://godbolt.org/z/4PkTIE) by checking the code produced for various compilers and targets (spoiler: it's always an `ASR` opcode of some kind):

```c
int asr(int x)
{
    return x >> 5;
}
```

The [SEI CERT C Coding Standard's INT13-C](https://wiki.sei.cmu.edu/confluence/display/c/INT13-C.+Use+bitwise+operators+only+on+unsigned+operands) page makes a big deal out of this, even assessing its risk as "high", but it's actually conflating different things with VERY different risk profiles:

* Shifts by values greater than the size of the operand **(undefined behavior, high risk)**
* Shifts by negative values **(undefined behavior, high risk)**
* Left shifts that change the sign of a signed integer from 1 to 0 **(undefined behavior, high risk)**
* Right shifts on signed integers **(implementation defined, virtually nonexistent risk)**
