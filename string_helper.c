#include "monty.h"

/**
 * is_number - check to see if input is a number
 * @s: input tpo examine
 * Return: 1 if number, o ele
 */

int is_number(char *s)
{
	int i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (*(s + i) != '\0')
	{
		if (*(s + i) >= '0' && *(s + i) <= '9')
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

/**
 * get_tokens - get tokens from line
 * @line: line from file
 * @line_num: line number
 * Return: int
 */
char *get_tokens(char *line, unsigned int line_num)
{
	char delim[2] = "\n";
	char *token = NULL;
	char *holder = NULL;

	token = strtok(line, delim);
	if (token == NULL)
		return (NULL);
	holder = strtok(NULL, delim);
	if (holder != NULL)
	{
		if (is_number(holder))
			global_var = atoi(holder);
		else
		{
			printf("L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
	}
	else if (holder == NULL && strcmp(token, "push") == 0)
	{
		printf("L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	return (token);
}
