#include "monty.h"
/**
 * get_op_func - gets the function
 * @cmd: command
 * Return: pointer to function
 */
void (*get_op_func(char *cmd))(stack_t **, unsigned int)
{
	int a = 0;
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{NULL, NULL}
	};
	while (ops[a].f && strcmp(ops[a].opcode, cmd) != 0)
	{
		a++;
	}
	return (ops[a].f);
}
