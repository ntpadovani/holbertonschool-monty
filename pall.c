#include "monty.h"

/**
 * pall - a function that prints all the elements of a list_t list.
 * @h: pointer to first element of the linked list.
 *
 * Return: the number of nodes.
 */

void pall(stack_t **head, __attribute__((unused))unsigned int line_number)
{
	const stack_t *ptr = *head;

	while(ptr != NULL)
	{
		printf("%d\n", (*ptr).n);
		printf("................\n");
		ptr = (*ptr).next;
	}
	return;
}
