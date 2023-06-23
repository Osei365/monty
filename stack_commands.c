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
	stack_t *new, *tmp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}

	val = strtok(NULL, "\n ");
	if (val && check_num(val) == 1)
		int_val = atoi(val);
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	new->n = int_val;
	if ((*head)->n == 0)
	{
		tmp = (*head)->next;
		new->prev = *head;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*head)->next = new;
	}
}

/**
 * op_pall - displays stack data
 * @head: head of stack
 * @line_number: number to insert val
 * Return: nothing
 */
void op_pall(stack_t **head, unsigned int line_number)
{
	stack_t *twin = (*head)->next;

	(void)line_number;
	while (twin)
	{
		fprintf(stdout, "%d\n", twin->n);
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

	if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
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
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(head, 0);
}

/**
 * op_swap - swaos node
 * @head: head of stack
 * @line_number: number to insert val
 */
void op_swap(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = (*head)->next;
	int num;

	if (ptr == NULL || ptr->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	num = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = num;
}
