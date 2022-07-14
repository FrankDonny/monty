#include "monty.h"
/**
 * main - main program
 * @argc: number arguments
 * @argv: strings passed
 * Return: 0 on success
 */
int main(size_t argc, char **argv)
{
	stack_t *stack;
	FILE *file;
	char *buffer = NULL, *line[2] = {NULL, NULL};
	size_t len = 0, count = 1;
	int nums;
	void (*f)(stack_t **stack, unsigned int line_num);

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nums = getline(&buffer, &len, file)) != -1)
	{
		line[0] = strtok(buffer, " \t\n");
		if (line[0] && line[0][0] != '#')
		{
			f = get_opcode(line[0]);
			if (!f)
			{
				fprintf(stderr, "L%ld: unknown instruction %s\n", count, line[0]);
				exit(EXIT_FAILURE);
			}
			f(&stack, count);
		}
		count++;
	}
	free(&stack);
	fclose(file);
	return (0);
}
