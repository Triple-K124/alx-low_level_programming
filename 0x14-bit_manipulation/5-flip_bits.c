#include "main.h"

/**
 * flip_bits - Counts the number of bits to be flipped from n to m.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned long int xor_ans = n ^ m;
    unsigned int count = 0;

    while (xor_ans != 0)
    {
        count += xor_ans & 1;
        xor_ans >>= 1;
    }

    return count;
}
