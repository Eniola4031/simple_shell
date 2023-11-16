#include "shell.h"

int main() {
    char input[256];
    char *command;

    while (1) {
       /* Display the prompt*/
        printf(PROMPT);

        /* Read the user's input */
        fgets(input, sizeof(input), stdin);

        /* Remove the newline character from the input */
        input[strlen(input) - 1] = '\0';

        /* Check for the "end of file" condition (Ctrl+D) */
        if (feof(stdin)) {
            printf("\n");
            break;
        }

        /* Tokenize the input to extract the command */
        command = strtok(input, " ");

        /* Check if an executable can be found */
        if (access(command, F_OK) == 0) {
            /* Execute the command */
            execve(command, NULL, environ);

            /* Handle errors */
            perror("Error executing command");
        } else {
            /* Display an error message */
            printf("Command not found: %s\n", command);
        }
    }

    return 0;
}
