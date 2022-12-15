#include "monty.h"
/**
 * add_func - add valuse of the node top
 * @stack: stack
 * @line_num: line number
 *
 */
void add_func(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;
	int sum = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	sum = temp->n + temp->next->n;
	temp->next->n = sum;

	pop_func(stack, line_num);
}
/**
 * sub_func - substract the top element from the second top
 * @stack: stack
 * @line_num: line number
 */
void sub_func(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;
	int diff = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	diff = temp->next->n - temp->n;
	temp->next->n = diff;

	pop_func(stack, line_num);
}
/**
 * mul_func - multiplies the second top element of the stack with the top
 * @stack: stack
 * @line_num: line number
 *
 */
void mul_func(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;
	int factor = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	factor = temp->next->n * temp->n;
	temp->next->n = factor;

	pop_func(stack, line_num);
}

/**
 * div_func - divides the second top element of the stack
 * by the element of the top element
 * @stack: stack
 * @line_num: line number
 */
void div_func(stack_t **stack, unsigned int line_num)
{
	stack_t *temp = NULL;
	int qtt = 0;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		printf("L%d: can't div, stavk too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		printf("L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	qtt = temp->next->n / temp->n;
	temp->next->n = qtt;

	pop_func(stack, line_num);
}
