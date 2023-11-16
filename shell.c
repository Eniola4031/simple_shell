#include "shell.h"

int main() {
    char command[100];
    int status;

    while (1) {
        // Display the prompt
        printf("simple_shell$ ");

        // Read the command from the user
        if (!fgets(command, sizeof(command), stdin)) {
            // Handle end of file condition (Ctrl+D)
            printf("\n");
            exit(0);
        }

        // Remove the trailing newline character
        command[strlen(command) - 1] = '\0';

        // Check if the command is empty
        if (strlen(command) == 0) {
            continue;
        }

        // Fork a child process
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            execl(command, command, NULL, environ);

            // If execl fails, print an error message and exit
            printf("Error: Cannot execute command '%s'\n", command);
            exit(1);
        } else if (pid > 0) {
            // Parent process
            wait(&status);

            if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
                printf("Error: Command '%s' exited with status %d\n", command, WEXITSTATUS(status));
            }
        } else {
            // Fork failed
            printf("Error: Fork failed\n");
            exit(1);
        }
    }

    return 0;
}
