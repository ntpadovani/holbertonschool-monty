#include "monty.h"

/**
 * swap - swaps top two elements of the stack
 * @head: The stack
 * @line_number: Line number of the instruction
 * Return: void
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;

	if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
	ptr = (*head)->next;
	(*head)->prev = ptr;
	(*head)->next = ptr->next;
	ptr->prev = NULL;
	ptr->next = *head;
	*head = ptr;
}