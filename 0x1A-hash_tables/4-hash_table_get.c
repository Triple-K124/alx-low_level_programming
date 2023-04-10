#include "hash_tables.h"
#include <string.h>
#include <stddef.h>

/**
 * hash_table_get - this function returns the value to each key
 * @ht: This is the table that stores the whole data both key and value
 * @key: This is the key that will be hashed and indexed
 *
 * Return: The function returns the value to the key
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int k_index;
	hash_node_t *get;

	k_index = key_index((const unsigned char *) key, ht->size);
	get = ht->array[k_index];
	while (get)
	{
		if (strcmp(get->key, key) == 0)
		{
			return (get->value);
		}
		get = get->next;
	}
	return (NULL);
}
