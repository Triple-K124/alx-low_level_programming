#include "hash_tables.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int hash_table_set(hash_table_t *ht, const char *key, const char *value)

{
	hash_node_t *check;
	unsigned long int k_index;
	hash_node_t* new_node;
	if (!ht || !key)
	{
		/* Hash table or key doesn't exist */
		fprintf(stderr, "Hash Table or key doesn't exist");
		return (0);
	}

	k_index =  key_index((const unsigned char *) key, ht->size);

	/* Check if the key already exists in the hash table */
	check = ht->array[k_index];
	while(check)
	{
		if (strcmp(check->key, key) == 0)
		{
			/* key already exists, update value */
			free(check->value);
			check->value = strdup(value);
			return (1);
		}
		check = check->next;
	}

	/* Allocate memory for a new node */
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
	{
		fprintf(stderr, "New memory was not allocated");
		return (0);
	}

	/* Initialize the new node with the key and value */
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = ht->array[k_index];
	ht->array[k_index] = new_node;


	return (1);
}
