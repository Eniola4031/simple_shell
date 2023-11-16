#include "main.h"

/**
 * main -  This function is the entry point for the simple_shell program.
 * It prompts the user for a command, executes it, and handles errors.
 *
 * Description: Display a prompt
 *
 * Return: always zero
 */
	int main(void)
{
		char line[MAX_LINE_LENGTH];

		while (1)
		{
			printf("simple_shell> ");

			fgets(line, MAX_LINE_LENGTH, stdin);
			if (feof(stdin))
				break;
			if (strlen(line) <= 1)
				continue;
			line[strlen(line) - 1] = '\0';  /* Remove the newline character */
			if (system(line) != 0)
				printf("Command not found\n");
		}
		return (0);
}
