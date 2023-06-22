#include "monty.h"
/**
 * add_dnodeint - adds a node to dll
 * @head: head of dll
 * @n: data to be added
 * Return: nothing
 */
void add_dnodeint(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new || !head)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head == NULL)
	{
		new->next = NULL;
	}
	else
	{
		(*head)->prev = new;
		new->next = *head;
	}
	new->prev = NULL;
	*head = new;
}

/**
 * add_dnodeint_end - add node to end of dll
 * @head: head of dll
 * @n: data to be added
 * Return: new  node head
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *current = *head;

	new = malloc(sizeof(stack_t));
	if (!new || !head)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
	new->prev = current;

	return (new);
}

/**
 * free_dlistint - frees a dll
 * @head: head of dll
 * Return: nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *current;

	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}

/**
 * delete_dnodeint_at_index - deletes node at index
 * @head: head of dll
 * @index: index position to be deleted
 * Return: 1 or -1
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *temp, *current, *ptr = *head;
	unsigned int count = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0 && *head)
	{
		current = (*head)->next;
		free(*head);
		if (current)
			current->prev = NULL;
		*head = current;
		return (1);
	}
	while (ptr)
	{
		if (count == index)
		{
			current = ptr->next;
			temp = ptr->prev;
			if (current)
				current->prev = temp;
			temp->next = current;
			free(ptr);
			return (1);
		}
		ptr = ptr->next;
		count++;
	}
	return (-1);
}
