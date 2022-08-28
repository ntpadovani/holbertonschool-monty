#include "monty.h"

/**
 * get_op_func - Selects the correct function to execute.
 * @s: Operator passed as argument.
 * Return: Pointer to function.
 */

void (*get_op_func(char *s))(stack_t **head, unsigned int line_number)
{
	 static instruction_t ops[] =	{
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
int idx = 0;
	/*printf("The contents of S:%s\n", s);*/ /*for debuging*/
	while (ops[idx].opcode)/* Traverse struct array ops*/
	{
		if(s == NULL)
		{
			return NULL;
		}
		if (strcmp(s, ops[idx].opcode) == 0)
		{
			return (ops[idx].f);/*Return function pointer (f)*/
		}
	
		idx++;
	}
	return (ops[idx].f);
}
