#include "main.h"

void exe_cmd(char *arguments[]) {
	if (access(arguments[0], X_OK) != -1) {
		pid_t child_pid = fork();
		
		if (child_pid == -1) {
			perror("error");
		} else if (child_pid == 0) {
			if (execvp(arguments[0], arguments) == -1) {
				perror("error");
				
				exit(EXIT_FAILURE);
			}
		} else {
			int status;
			waitpid(child_pid, &status, 0);
		}
	} else {
		printf("error\n");
	}
}
