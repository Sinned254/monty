#include "monty.h"
/**
 * push_func - push element to a stack
 * @stack: stack
 * @line_num: line number
 */
void push_func(stack_t **stack, unsigned int line_num)
{
	stack_t *new = NULL;

	(void) line_num;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = global_var;
	new->prev = NULL;

	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
		return;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}
/**
 * pall_func - prints all the values on the stack top-bootom
 * @stack: stack
 * @line_num: line number
 */
void pall_func(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;

	(void) line_num;
	temp = *stack;
	if ((*stack) == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint_func - prints the value at the top of the stack
 * @stack: stack
 * @line_num: line number
 */
void pint_func(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;

	if (*stack == NULL || stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	printf("%d\n", temp->n);
}
/**
 * pop_func - pop the node at the top
 * @stack: stack
 * @line_num: line number
 */

void pop_func(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (*stack == NULL || stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * get_func - match opcode from input to opcode in struct
 * @op: character
 * @stack: satck
 * @line_num: line number
 */

void get_func(char *op, stack_t **stack, unsigned int line_num)
{
	instruction_t find_op[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"nop", nop_func},
		{"add", add_func},
		{"swap", swap_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{NULL, NULL}
	};
	int i = 0;

	while (find_op[i].opcode != NULL)
	{
		if (strcmp(find_op[i].opcode, op) == 0)
		{
			find_op[i].f(stack, line_num);
			return;
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", line_num, op);
	exit(EXIT_FAILURE);
}
