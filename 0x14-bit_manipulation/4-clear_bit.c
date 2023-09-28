#include "main.h"

/**
 * clear_bit - Make the value of a bit to 0 at any index.
 * @n: A pointer to the number to we are trying to modify.
 * @index: The index of the bit to clear (0-based).
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8)
        return (-1);
    
    *n = *n & ~(1 << index);
    return (1);
}
