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
		/*{"pint", pint},
		*{"pop", pop},
		*{"swap", swap},
		*{"add", add},
		*{"nop", nop},
		*/
		{NULL, NULL}
	};
int idx = 0;

	while (ops[idx].opcode)/*navego por el struct array ops*/
	{
		if (strcmp(s, ops[idx].opcode) == 0)
		{
			return (ops[idx].f);/*devuelvo un function pointer (f)*/
		}
		idx++;
	}
	return (ops[idx].f);
}
