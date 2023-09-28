#include "main.h"

/**
 * set_bit - Sets the number of a bit to 1 to an index.
 * @n: A pointer to the number that we are trying to modify.
 * @index: The index of the bit to set we set at 0.
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8)
        return (-1); 
    
    *n = *n | (1 << index); 
    return (1);
}
