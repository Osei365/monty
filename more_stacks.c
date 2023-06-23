#include "monty.h"
/**
 * op_mod - divide top two elements in stack
 * @head: head of stack
 * @line_number: line number
 */
void op_mod(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n %= (*head)->n;
	delete_dnodeint_at_index(head, 0);
}

