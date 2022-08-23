#include "monty.h"

/**
 * push - adds a new node at the beginning of a link list
 * @head: input header pointer
 * @line_number: function used to count the lines
 * Return: address of the new element, or NULL if it failed
 */

void push(stack_t **head, __attribute__((unused))unsigned int line_number)
{
	stack_t *new_node = NULL;
	char *montycontent = NULL;
	int idx = 0;
	montycontent = montycmd[1];
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		return;
	}
	printf("montycmd is:%s\n", montycontent);
	while (montycontent[idx] != '\0')
	{
		if(isalpha(montycontent[idx]) != 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit (EXIT_FAILURE);
		}
		idx++;
	}
	
	
	new_node->n = atoi(montycmd[1]); /*converti de string a int*/
	new_node->prev = NULL;
	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}
