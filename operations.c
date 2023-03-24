#include "monty.h"

/**
 * set_ops - sets the opcodes and functions
 */

void set_ops(void)
{
	instruction_t ops[] = {
		{"push", push},
		{"pop", pop},
		{NULL, NULL}
	};

}


/**
 * monty - runs monty opertations
 * @stack: stack
 * @ops: operations list
 * @opcode: option code
 * @line_number: file line number
 */

void monty(stack_t stack, instruction_t ops, char *opcode, int line_number)
{
	int i;

	for (i = 0; ops[i]; i++)
	{
		if (strcmp(ops[i].opcode, opcode) == 0)
		{
			ops[i].f(stack, line_number);
			break;
		}
	}
}
