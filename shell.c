#include "main.h"

/**
 * main - Code entry point
 *
 * Description: main file for prompt
 *
 * Return: returns 0 (sucess)
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
