#include "monty.h"
/**
 * op_stack - change mode to stack
 * @head: head of stack
 * @line_number: line number in monty file
 */
void op_stack(stack_t **head, unsigned int line_number)
{
	flag = 0;

	(void)head;
	(void)line_number;
}

/**
 * op_queue - change mode to queue
 * @head: head of stack
 * @line_number: line number
 */
void op_queue(stack_t **head, unsigned int line_number)
{
	flag = 1;

	(void)head;
	(void)line_number;
}
