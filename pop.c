#include "monty.h"

/**
 * pop - deletes the node at index
 * @head: head of linked list
 * @line_number:  index of the node that should be deleted
 * Return: nothing
 */


void pop(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;

	if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        free(*head);
		exit (EXIT_FAILURE);
    }

	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		ptr = (*head)->next;
		(*head) = ptr;
		ptr = ptr->prev;
		(*head)->prev = NULL;
		free(ptr);
	}
}