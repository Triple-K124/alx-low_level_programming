#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * hash_table_create - creates a new hash table
 * @size: size of the hash table
 *
 * Return: a pointer to the new hash table, or NULL if an error occurred
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned int i;
	hash_table_t *table = (hash_table_t *)malloc(sizeof(hash_table_t));

	if (!table)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	table->size = size;
	table->array = calloc(table->size, sizeof(hash_node_t *));
		if (!table->array)
		{
			fprintf(stderr, "Error: calloc failed\n");
			return (NULL);
		}
	for (i = 0; i < size; i++)
		table->array[i] = NULL;
	return (table);
}
