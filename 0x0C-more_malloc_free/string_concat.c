#include <stdio.h>
#include <stdlib.h>
#include "main.h"

unsigned int _strlen(char* s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
		return (i);
}
char* string_nconcat(char* s1, char* s2, unsigned int n)
{
	char* ptr;
	unsigned int sum1, sum2, i;

	if (s1 == NULL)
	return " ";

	if (s2 == NULL)
	return " ";

	sum1 = _strlen(s1);
	sum2 = _strlen(s2);

	ptr = (char*) malloc ((sum1 + sum2 + 1) * sizeof(char));
	if (ptr == NULL)
	return NULL;
	for (i = 0; i < sum1; i++)
		ptr[i] = s1[i];
	for (i = 0; i < sum2; i++)
		ptr[i] = s2[i - sum1];

	ptr[i] = '\0';

	return (ptr);
}
