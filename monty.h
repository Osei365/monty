#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int flag;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int stack_init(stack_t **head);
void add_dnodeint(stack_t **head, const int n);
void add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void parse_file(char *filename, stack_t **head);
char *get_command(char *buffer);
void (*get_op_func(char *cmd))(stack_t **, unsigned int);
void op_push(stack_t **head, unsigned int line_number);
void op_pall(stack_t **head, unsigned int line_number);
void op_pint(stack_t **head, unsigned int line_number);
void op_pop(stack_t **head, unsigned int line_number);
void op_swap(stack_t **head, unsigned int line_number);
void op_add(stack_t **head, unsigned int line_number);
void op_nop(stack_t **head, unsigned int line_number);
void op_sub(stack_t **head, unsigned int line_number);
void op_div(stack_t **head, unsigned int line_number);
void op_mul(stack_t **head, unsigned int line_number);
void op_mod(stack_t **head, unsigned int line_number);
void op_pchar(stack_t **head, unsigned int line_number);
void op_pstr(stack_t **head, unsigned int line_number);
void op_rotl(stack_t **head, unsigned int line_number);
void op_rotr(stack_t **head, unsigned int line_number);
void op_stack(stack_t **head, unsigned int line_number);
void op_queue(stack_t **head, unsigned int line_number);
int check_num(char *val);
#endif
