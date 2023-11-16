#include "shell.h"

int main() {
  char command[100];
  int status;

  while (1) {
    printf(PROMPT);

    // Get the user's command
    if (fgets(command, sizeof(command), stdin) == NULL) {
      if (feof(stdin)) {
        printf("\n");
        exit(0);
      } else {
        perror("fgets");
        exit(1);
      }
    }

    // Remove the newline character from the command
    command[strlen(command) - 1] = '\0';

    // Check if the command is an empty string
    if (strlen(command) == 0) {
      continue;
    }

    // Execute the command using execve
    status = execve(command, NULL, NULL);

    if (status == -1) {
      printf("Command not found: %s\n", command);
    } else {
      printf("Error executing command: %s\n", command);
    }
  }

  return 0;
}
