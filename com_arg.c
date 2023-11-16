#include "main.h"

void com_arg(const char *message) {
	write(STDOUT_FILENO, message, strlen(message));
}
