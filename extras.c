#include "monty.h"
/**
 * check_num - checks if a str is int
 * @val: value to evaluate
 * Return: 1 or 0
 */
int check_num(char *val)
{
	int a = 0;

	while (val[a])
	{
		if (val[a] == '-')
		{
			a++;
			continue;
		}
		if (!isdigit(val[a]))
			return (0);
		a++;
	}
	return (1);
}
