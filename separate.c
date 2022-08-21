#include "monty.h"

/**
 *separate - A function that splits a
 *            string and returns an array
 *            of each word of the string.
 *@string: The string containing the words.
 *@s: The delimiter.
 *Return:  An array for each word found inside the string.
 */

char **separate(char *string, const char *s)
{
	char *tokenized = NULL, **darray = NULL;
	int size = 0, idx = 0;
	size = count_words(string);
	printf("Size is:%d\n", size);
	darray = malloc(sizeof(char *) * size + 1);
	if (darray == NULL)
	{
		return NULL;
	}
	tokenized = strtok(string, s);
	while (tokenized != NULL)
	{
		/*darray[idx] = malloc(sizeof(char) * _strlen(tokenized) + 1);
		if (darray[idx] == NULL)
		{
			free(darray);
			return (NULL);
		}*/
		darray[idx] = tokenized;

		idx++;
		tokenized = NULL;
		tokenized = strtok(NULL, s);
	}
	return (darray);
}
