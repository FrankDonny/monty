#include "monty.h"

/**
 * swap - swap function swaps the numbers of the top most 2 nodes
 * @stack: pointer to the stack
 * @line_num: line number it the swap occured
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;
	int count = 1, num;
	/*
	 * if (*stack == 0)
	 * return;
	 */
	temp = *stack;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	num = temp->n;
	temp->n = temp->next->n;
	temp->next->n = num;
}

/**
 * add - swap function swaps the numbers of the top most 2 nodes
 * @stack: pointer to the stack
 * @line_num: line number it the addition occured
 */
void add(stack_t **stack, unsigned int line_num)
{
	int sum = 0, count = 0;
	stack_t *temp;

	temp = *stack;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sum += (temp->n + temp->prev->n);
	temp->prev->n = sum;
}
