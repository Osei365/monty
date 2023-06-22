#define  _POSIX_C_SOURCE 200809L
#include "monty.h"
/**
 * parse_file - parses file and gets command
 * @filename: filanme from argv[]
 * @head: stack head
 * Returns: nothing
 */
void parse_file(char *filename, stack_t **head)
{
	char *buffer = NULL;
	char *cmd;
	size_t bufsize = 32;
	int nchars, flc;
	unsigned int count = 1;
	void (*func)(stack_t **, unsigned int);
	FILE *fl = fopen(filename, "r");

	if (fl == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		if (*head)
			free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	while ((nchars = getline(&buffer, &bufsize, fl)) != -1)
	{
		cmd = get_command(buffer);
		if (cmd == NULL || cmd[0] == '#')
		{
			count++;
			continue;
		}
		func = get_op_func(cmd);
		if (func == NULL)
		{
			printf("L%d: unknown instruction %s\n", count, cmd);
			if (*head)
				free_dlistint(*head);
			exit(EXIT_FAILURE);
		}
		func(head, count);
		count++;
	}
	free(buffer);
	flc = fclose(fl);
	if (flc == -1)
		exit(-1);
}

/**
 * get_command - gets command from line
 * @buffer: buffer of characters
 * Return: command
 */
char *get_command(char *buffer)
{
	char *command;

	command = strtok(buffer, "\n ");
	if (command == NULL)
		return (NULL);
	return (command);
}
