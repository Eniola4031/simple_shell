#include "main.h"
/**
 * main - Code entry point
 *
 * Description: main file for prompt
 *
 */
void rd_cmd(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			com_arg("\n");
			exit(EXIT_SUCCESS);
		} else
		{
			com_arg("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0'; /* Remove newline */
}
