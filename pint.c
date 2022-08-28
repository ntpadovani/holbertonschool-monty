#include "monty.h"

/**
 * pint - Print the value at the top of the stack
 *
 * @head: Head pointer
 * @line_number: function used to count the lines
 *
 * Return: Nothing
 */

void pint(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
    const stack_t *ptr = *head; /*apunto el pointer al head pointer*/

    if (ptr == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*ptr).n);
}