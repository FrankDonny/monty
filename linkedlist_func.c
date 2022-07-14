#include "monty.h"

/**
 * addnode - adds a new node to the linkedlist
 * @stack: pointer to the stack
 * @num: number of the node
 * Return: newNode
 */
stack_t *addnode(stack_t **stack, const int num)
{
	stack_t *newNode, *temp;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = num;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (*stack == NULL)
	{
		*stack = newNode;
		return (*stack);
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
	temp = newNode;
	return (newNode);
}

/**
 * del_node - deletes a node from the linkedlist
 * @stack: pointer to the stack
 * @idx: index to be deleted
 * Return: nothing
 */
void del_node(stack_t **stack, const int idx)
{
	stack_t *temp;
	int i;

	temp = *stack;
	if (idx == 0)
	{
		*stack = temp->next;
		temp = temp->next;
	}
	for (i = 0; i < idx - 1; i++)
	{
		temp = temp->next;
		temp->next = temp->next->next;
		temp->next->prev = temp;
	}
}
