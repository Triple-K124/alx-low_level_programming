#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash_tables.h"

/**
 * key_exists - checks if the key really exists.
 * @ht: stores the hash table.
 * @key: the key of the string.
 * @value: the value that will be stored in the string
 *
 * Return: Returns 0 if successful
 */

int key_exists(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int k_index;
	hash_node_t *check;

	k_index = key_index((const unsigned char *) key, ht->size);
	check = ht->array[k_index];
	while (check)
	{
		if (strcmp(check->key, key) == 0)
		{
			/* Key already exists, update value */
			free(check->value);
			check->value = strdup(value);
			return (1);
		}
		check = check->next;
	}
	return (0);
}
/**
 * update_value - updates the value of the key.
 * @ht: stores the hash table.
 * @key: the key of the string.
 * @value: the value that will be stored in the string
 *
 * Return: Returns 0 if successful
 */

int update_value(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *check;

	check = ht->array[key_index((const unsigned char *) key, ht->size)];
	while (check)
	{
		if (strcmp(check->key, key) == 0)
		{
			free(check->value);
			check->value = strdup(value);
			return (1);
		}
		check = check->next;
	}
	return (0);
}

/**
 * create_node - creates new node.
 * @key: the key of the string.
 * @value: the value that will be stored in the string
 *
 * Return: Return 0 if successful
 */

hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node;

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
	{
		fprintf(stderr, "New memory was not allocated");
		return (NULL);
	}
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	new_node->next = NULL;
	return (new_node);
}
/**
 * hash_table_set - Addition of the key into the table
 * @ht: This is the table itself
 * @key: The key that would be added
 * @value: The value that is tied with the key
 *
 * Return: The new table that has been added a new new
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{

	hash_node_t *new_node;
	unsigned long int k_index;

	if (!ht || !key)
	{
		fprintf(stderr, "Hash table or key doesn't exist");
		return (0);
	}

	if (key_exists(ht, key, value))
	{
		update_value(ht, key, value);
		return (1);
	}

	new_node = create_node(key, value);
	if (!new_node)
	{
		return (0);
	}

	k_index = key_index((const unsigned char *) key, ht->size);
	new_node->next = ht->array[k_index];
	ht->array[k_index] = new_node;

	return (1);
}

