#include "monty.h"

/**
 * arrayfree - Used to free an array.
 *@string: The array to be freed.
 *
 * Return: Void
 */

void arrayfree(char **string)
{
	int idx;

	for(idx = 0; string[idx] != NULL; idx++)
	{
		free(string[idx]);
	}
	free(*string);
	string = NULL;
}

/**
 * freestack - Used to free a stack
 * @mystack: The stack to be freed.
 *
 *Return: Void 
 */
void freestack(stack_t *mystack)
{
	
	if(mystack == NULL)
	{
		return;
	}
	freestack((*mystack).next);
	free(mystack);
	mystack = NULL;
}


