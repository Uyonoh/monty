#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void execute(char *line);

/**
 * main - Entry point
 * @argc: no of args
 * @argv: argument variables
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	char *line;
	size_t len;
	ssize_t read;

	if (argc == 2)
	{
		fp = fopen(argv[1], "r");
		if (fp == NULL)
		{
			exit(EXIT_FAILURE);
		}
		while ((read = getline(&line, &len, fp)) != -1)
		{
			execute(line);
		}
		fclose(fp);
		if (line)
		{
			free(line);
		}
	}

	return(0);
}

/**
 * execute - run a monty command
 * @line: command line
 *
 * Return: void
 */

void execute(char *line)
{
	char *cmd;

	cmd = strtok(line, " ");

	printf("%s\n", cmd);
}
