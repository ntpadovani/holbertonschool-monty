#include "monty.h"

/**
 * pall - a function that prints all the elements of a linked list.
 *	@head: head pointer
 *	@line_number: function used to count the lines
 * Return: the contents of all the nodes in a linked list.
 */

void pall(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	const stack_t *ptr = *head; /*apunto el pointer al head pointer*/
	/*int idx;*/
	while (ptr != NULL)
	{
		printf("%d\n", (*ptr).n);
		ptr = (*ptr).next; /*para correr de nodo en nodo*/
	}

/*	if(montycmd[1] != NULL)
	{
		for(idx = 1; montycmd[idx] != NULL; idx++)
		{
			printf("%s", montycmd[idx]);
		}
	}*/
	/*if (ptr == NULL)
	{

		exit(EXIT_SUCCESS);
	}*/
}