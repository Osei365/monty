#include "monty.h"
/**
 * op_push - pushs to stack
 * @head: head of stack
 * @line_number: number to insert val;
 * Return: nothing
 */
void op_push(stack_t **head, unsigned int line_number)
{
	int int_val;
	char *val;

	val = strtok(NULL, "\n ");
	if (val && check_num(val) == 1)
		int_val = atoi(val);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(head, int_val);
}

/**
 * op_pall - displays stack data
 * @head: head of stack
 * @line_number: number to insert val
 * Return: nothing
 */
void op_pall(stack_t **head, unsigned int line_number)
{
	stack_t *twin = *head;

	(void)line_number;
	while (twin)
	{
		printf("%d\n", twin->n);
		twin = twin->next;
	}
}

/**
 * op_pint - pints
 * @head: head of stack
 * @line_number: number to insert val
 */
void op_pint(stack_t **head, unsigned int line_number)
{
	stack_t *twin = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", twin->n);
}

/**
 * op_pop - removes node from top
 * @head: head of stack
 * @line_number: number to insert val
 */
void op_pop(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(head, 0);
}
