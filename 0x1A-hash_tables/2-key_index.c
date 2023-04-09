#include "hash_tables.h"
/**
 * size - size of the Table`
 * @key: key that holds the the value
 *
 * Return: index_value
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{

	unsigned long int index_key = hash_djb2(key) % size;

	return (index_key);

}
