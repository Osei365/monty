#include "monty.h"
/**
 * main - Entry point
 * @ac: arg count
 * @av: arg vector
 * Return: 1 or 0
 */
int main(int ac, char *av[])
{
	stack_t *head;

	head = NULL;
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		if (head)
			free_dlistint(head);
		exit(EXIT_FAILURE);
	}
	parse_file(av[1], &head);
	return (0);
}
