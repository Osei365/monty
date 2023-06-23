#include "monty.h"
/**
 * op_add - adds first two
 * @head: head of stack
 * @line_number: line number in stack
 */
void op_add(stack_t **head, unsigned int line_number)
{
	stack_t *twin = (*head)->next, *ptr;
	int num;

	if (twin == NULL || twin->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	ptr = twin->next;
	num = twin->n + ptr->n;
	ptr->n = num;
	delete_dnodeint_at_index(head, 0);
}

/**
 * op_nop - does nothing
 * @head: head of stack
 * @line_number: line number in stack
 */
void op_nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	;
}

/**
 * op_sub - substracts top two
 * @head: head of stack
 * @line_number: line number in stack
 */
void op_sub(stack_t **head, unsigned int line_number)
{
	stack_t *twin = (*head)->next;

	if (twin == NULL || twin->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	twin->next->n -= twin->n;
	delete_dnodeint_at_index(head, 0);
}

/**
 * op_div - divide top two elements in stack
 * @head: head of stack
 * @line_number: line number
 */
void op_div(stack_t **head, unsigned int line_number)
{
	stack_t *twin = (*head)->next;

	if (twin == NULL || twin->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	if (twin->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	twin->next->n /= twin->n;
	delete_dnodeint_at_index(head, 0);
}

/**
 * op_mul - multiply top two
 * @head: head of stack
 * @line_number: line number
 */
void op_mul(stack_t **head, unsigned int line_number)
{
	stack_t *twin = (*head)->next;

	if (twin == NULL || twin->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	twin->next->n *= twin->n;
	delete_dnodeint_at_index(head, 0);
}
