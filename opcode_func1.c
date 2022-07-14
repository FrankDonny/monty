#include "monty.h"

/**
 * push - item to the stack
 * @stack: pointer to the stack
 * @line_number: line number where the push occured
 */
void push(stack_t **stack, unsigned int line_number)
{
        stack_t *new;
        char *arg;
        int push_arg;

        push_arg = 0;
        new = malloc(sizeof(stack_t));
        if (!new)
        {
                printf("Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

        arg = strtok(NULL, "\n ");
        if (isNumber(arg) == 1 && arg != NULL)
        {
                push_arg = atoi(arg);
        }
        else
        {
                printf("L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
        }

        
        addnode(stack, push_arg);
}

/**
 * pall - print all items on the stack
 * @stack: pointer to the stack
 * @line_number: line number where the pall occured
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
        stack_t *temp;

        while (temp->next != NULL)
        {
                fprintf(stdout, "%i\n", (*stack)->n);
        }
}

/**
 * pop - deletes the top item on the stack
 * @stack: pointer to the stack
 * @line_number: line number where the pop occured
 */
void pop(stack_t **stack, unsigned int line_num)
{
        if (*stack == NULL)
        {
                fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
                exit(EXIT_FAILURE);
        }
        del_node(stack, 0);
}

/**
 * nop - Does nothing
 * @stack: pointer to the stack
 * @line_number: line number that the nop occured
 */
void nop(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
        ;
}

/**
 * isNumber - check if a string is an integer
 * 
 * @s: string to check
 * Return: 1 if not digit, else 1 
 */
int isNumber(char s[])
{
	int i;

        for (i = 0; s[i] != '\0'; i++)
        {
                if (isdigit(s[i]) == 0)
                        return 0;
        }
        return 1;
}
