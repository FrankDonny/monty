#include "monty.h"

/**
* stack_length - returns length of stack
* @stack: pointer to head of stack
* Return: length of stack
*/
size_t stack_length(stack_t **stack)
{
	stack_t *current;
	unsigned int n; /* counter for number of elements */

	current = *stack;
	n = 0;
	while (current != NULL)
	{
		current = current->next;
		n++;
	}

	return (n);
}

/**
* free_stack - frees a stack_t stack
* @stack: stack to be freed
* Return: void
*/
void free_stack(stack_t **stack)
{
	stack_t *current;

	while (*stack != NULL)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
}

/**
* free_all - frees line and fp
* @stack: stack to free
* @line: line to free from getline
* @fp: file pointer to free
* Return: void
*/
void free_all(stack_t *stack, char *line, FILE *fp)
{
	if (stack != NULL)
	free_stack(&stack);

	free(line);
	fclose(fp);
}

/**
 * _rotl - rotates the list left
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _rotl(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner;
	int temp1, temp2;

	if (*stack == NULL)
		return;
	runner = *stack;
	while (runner->next)
		runner = runner->next;
	while (runner)
	{
		if (!runner->next)
		{
			temp1 = runner->n;
			runner->n = (*stack)->n;
		}
		else
		{
			temp2 = runner->n;
			runner->n = temp1;
			temp1 = temp2;
		}
		runner = runner->prev;
	}
}
/**
 * _rotr - rotates the list right
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void _rotr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *runner1, *runner2;
	int temp1, temp2;

	if (*stack == NULL)
		return;

	runner1 = *stack;
	runner2 = *stack;
	while (runner1->next)
		runner1 = runner1->next;
	while (runner2)
	{
		if (runner2->prev == NULL)
		{
			temp1 = runner2->n;
			runner2->n = runner1->n;
		}
		else
		{
			temp2 = runner2->n;
			runner2->n = temp1;
			temp1 = temp2;
		}
		runner2 = runner2->next;

	}
}
