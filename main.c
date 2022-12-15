#include "monty.h"

/**
 * main - read/open monty file
 *
 * @ac: argument count
 * @av: aguments array
 *
 * Return: 0 success, 1 failure
 */
int main(int ac, char **av)
{
	FILE *fp;
	ssize_t bytes_read;
	size_t len = 0;
	char *line = NULL;
	char *token = NULL;
	int line_number = 0;
	stack_t *head = NULL;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fp = fopen(av[1], "r");
		if (fp == NULL)
		{
			printf("Error: can't open file %s\n", av[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			while ((bytes_read = getline(&line, &len, fp)) != -1)
			{
				line_number++;
				token = get_tokens(line, line_number);
				if (token != NULL)
					get_func(token, &head, line_number);
			}
			free(line);
			free_stack(head);
			fclose(fp);
		}
	}
	return (0);
}
