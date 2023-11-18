#include "main.h"

/**
 * com_arg - char message
 * Description: ooutpu user input
 */

void com_arg(const char *message)
{
	write(STDOUT_FILENO, message, strlen(message));
}
