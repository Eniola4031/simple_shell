#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void);
void dis_prmpt(void);
void com_arg(const char *message);
void rd_cmd(char *command, size_t size);
void exe_cmd(const char *command);


#endif
