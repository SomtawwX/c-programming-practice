/*Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
Explain why. Use this observation to write a faster version of bitcount. */

#include <stdio.h>

int bitcount(unsigned int x);

int main()
{
    // 255 in binary is 11111111, so the output should be 8 (8 bits set to 1)
    printf("There's %d 1's bits in this number", bitcount(255));
    return 0;
}

/*
 * bitcount: Counts the number of 1-bits in the binary representation of x.
 * This implementation uses the property of x &= (x-1) to efficiently count bits.
 * Each iteration removes the rightmost 1-bit from x, reducing the number of iterations.
 */
int bitcount(unsigned int x)
{
    int b = 0;

    for (b = 0; x != 0; x &= (x - 1))
    { 
        b++; // Increment the counter for each 1-bit found
    }

    return b;
}