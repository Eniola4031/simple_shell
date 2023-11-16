#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
  char line[MAX_LINE_LENGTH];

  while (1) {
    printf("simple_shell> ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    if (feof(stdin)) {
      break;
    }

    if (strlen(line) <= 1) {
      continue;
    }

    line[strlen(line) - 1] = '\0';  /* Remove the newline character */

    if (system(line) != 0) {
      printf("Command not found\n");
    }
  }

  return 0;
}
