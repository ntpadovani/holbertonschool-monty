#include "monty.h"

/**
 * add - adds the n value of the top two node, then pops.
 * @head: The stack (void)
 * @line_number: Line number of the instruction (void)
 * Return: void
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit (EXIT_FAILURE);
	}
	ptr = *head;
	if (ptr->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit (EXIT_FAILURE);
	}
	ptr->next->n += (*head)->n;
	*head = (*head)->next;
	free(ptr);
	(*head)->prev = NULL;
}