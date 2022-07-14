#include "monty.h"

/**
 * free - free the linked list
 * @stack: pointer to first node
 */
void free(stack_t *stack)
{
	stack_t *tmp;

	while (*head != NULL)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}
