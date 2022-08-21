#include "monty.h"

/**
 * pall - a function that prints all the elements of a linked list.
 * @h: pointer to first element of the linked list.
 *
 * Return: the contents of all the nodes in a linked list.
 */

void pall(stack_t **head, __attribute__((unused))unsigned int line_number)
{
	const stack_t *ptr = *head;/*apunto el pointer al head pointer*/

	while(ptr != NULL)
	{
		printf("%d\n", (*ptr).n);
		ptr = (*ptr).next;/*para correr de nodo en nodo*/
	}
	return;
}
