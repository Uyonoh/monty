#include "monty.h"


/**
 * monty - runs monty opertations
 * @stack: stack
 * @ops: operations list
 * @opcode: option code
 * @line_number: file line number
 */

void monty(stack_t **stack, char *opcode, int line_number)
{
	int i;
	
	instruction_t ops[] = {
		{"push", push},
		{"pop", pall},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode, opcode) == 0)
		{
			ops[i].f(stack, line_number);
			break;
		}
	}
}

void push(stack_t **stack, unsigned int line_number)
{
	/* char *line; */
	char *arg;
	int n;
	size_t pos;
	stack_t *new_stack;

	arg = strtok(NULL, " ");

	if (arg[strlen(arg)-2] == '$')
	{
		arg[strlen(arg)-2] = '\0';
	}
	n = str_toint(arg);
	
	
	printf("push>> %d, %s, %d\n", n, arg, line_number);
	pos = add_stack(stack);
	new_stack = stack[pos];
	new_stack->n = n;
	new_stack->next = NULL;
	
	if (pos == 0)
	{
		new_stack->prev = NULL;
	} else
	{
		new_stack->prev = stack[pos - 1];
		stack[pos - 1]->next = new_stack;
	}
}



size_t add_stack(stack_t **stack)
{
	stack_t *new_stack;
	size_t len;
	
	len = dlistint_llen(stack);
	new_stack = malloc(sizeof(stack_t));
	stack[len] = new_stack;
	
	return (len);
}

void pall(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;
	size_t pos;
	stack_t *new_stack;

	char line[] = "push 1";
	arg = strtok(line, " ");
	arg = strtok(NULL, " ");
	n = str_toint(arg);
	
	printf("push>> %d, %d\n", n, line_number);
	pos = add_stack(stack);
	new_stack = stack[pos];
	new_stack->n = n;
	new_stack->next = NULL;
	
	if (pos == 0)
	{
		new_stack->prev = NULL;
	} else
	{
		new_stack->prev = stack[pos - 1];
		stack[pos - 1]->next = new_stack;
	}
	
}
