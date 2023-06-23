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
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{NULL, NULL}
	};
	while (ops[a].f && strcmp(ops[a].opcode, cmd) != 0)
	{
		a++;
	}
	return (ops[a].f);
}

/**
 * stack_init - initiliazes stack
 * @head: head of stack
 * Return: a values
 */
int stack_init(stack_t **head)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (*head)
			free_dlistint(*head);
		return (EXIT_FAILURE);
	}

	new->n = 0;
	new->prev = NULL;
	new->next = NULL;

	*head = new;

	return (EXIT_SUCCESS);
}
