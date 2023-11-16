#include "main.h"

/*
 * main - Code entry point
 *
 * Description: This file prompts and execute shell commands
 *
 * Return: returns zero(sucess)
 */
	int main(void)
{
	char command[120];
	while (true)
	{
		dis_prmpt();
		rd_cmd(command, sizeof(command));
		exe_cmd(command);
	}

	return (0);
}
