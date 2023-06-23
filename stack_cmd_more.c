#include "monty.h"
/**
 * op_add - adds first two
 * @head: head of stack
 * @line_number: line number in stack
 */
void op_add(stack_t **head, unsigned int line_number)
{
	stack_t *twin = *head, *ptr;
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

