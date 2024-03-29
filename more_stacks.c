#include "monty.h"
/**
 * op_mod - divide top two elements in stack
 * @head: head of stack
 * @line_number: line number
 */
void op_mod(stack_t **head, unsigned int line_number)
{
	stack_t *twin = *head;

	if (twin == NULL || twin->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
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
	twin->next->n %= twin->n;
	delete_dnodeint_at_index(head, 0);
}

/**
 * op_pchar - converts ascii to char
 * @head: head os stack
 * @line_number: line number
 */
void op_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	if (temp == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", temp->n);
}

/**
 * op_pstr -prints the string starting at the top of the stack
 * @head: head of stack
 * @line_number: line number
 */
void op_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *twin = *head;

	(void)line_number;
	while (twin && twin->n != 0 && (twin->n > 0 && twin->n <= 127))
	{
		printf("%c", twin->n);
		twin = twin->next;
	}

	printf("\n");
}

/**
  * op_rotl - rotates the stack
  * @head: head of stack
  * @line_number - line number
  */
void op_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *first = *head;
	int num;

	(void)line_number;
	if (*head == NULL || (*head)->next == NULL)
		return;
	num = first->n;
	while (first->next)
	{
		first->n = first->next->n;
		first = first->next;
	}
	first->n = num;
}

/**
 * op_rotr - rotates the stack reverse
 * @head: head of stack
 * @line_number - line number
 */
void op_rotr(stack_t **head, unsigned int line_number)
{
	stack_t *bottom = *head;
	int num;

	(void)line_number;
	if (bottom == NULL || bottom->next == NULL)
		return;
	while (bottom->next)
		bottom = bottom->next;
	num = bottom->n;
	while (bottom->prev)
	{
		bottom->n = bottom->prev->n;
		bottom = bottom->prev;
	}
	bottom->n = num;
}
