#include "monty.h"

/**
 * get_op_func - selects the correct function to perform
 * @s: operator passed as argument
 * Return: pointer to function
 */

void (*get_op_func(char *s))(stack_t **head, unsigned int line_number)
{
	 instruction_t ops[] =	{
		{"push", push},
		{"pall", pall},
		/*
		*{"pint", pint},
		*{"pop", pop},
		*{"swap", swap},
		*{"add", add},
		*{"nop", nop},
		*/
		{NULL, NULL}
	};
int idx = 0;

	while (ops[idx].opcode)/* Traverse struct array ops*/
	{
		if (strcmp(s, ops[idx].opcode) == 0)
		{
			return (ops[idx].f);/*Return function pointer (f)*/
		}
		idx++;
	}
	if (ops[idx].f == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, s);
		exit(EXIT_FAILURE);
	}
	return (ops[idx].f);
}
