#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Prints the contents of the hash table
 * @ht: The hash table that we want to access
 *
 * Return: Returns nothing since the function is void
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t **show = NULL;
	hash_node_t *node;
	unsigned long int i;

	if (!ht)
		return;
	show = ht->array;
	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		node = show[i];
		while (node)
		{
			if (node != show[i])
				printf(",");
			printf("'%s': '%s'", node->key, node->value);
			node = node->next;
		}
	}
	printf("}\n");
}
