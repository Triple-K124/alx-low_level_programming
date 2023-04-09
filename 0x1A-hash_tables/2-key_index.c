#include "hash_tables.h"
/**
 * key_index - gives the index of the key
 * @key: the key, of the string.
 * @size: the size of the array of the hash table.
 *
 * Return: Index number for key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{

	unsigned long int index_key = hash_djb2(key) % size;

	return (index_key);

}
