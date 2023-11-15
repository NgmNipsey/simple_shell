#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

char *_get_line(void);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char **_tokenizer(char *s);
void _free(char **command);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _execute(char **cmd, char **av, int index);
char *_getenv(char *variable);
void _print_error(char *name, char *cmd, int index);
char *_getpath(char *cmd);
void _reverse_string(char *dest, int len);
char *_atoi(int num);

void print_env(char **cmd);
void handle_builtin(char **av);
int is_builtin(char *av);

#endif /* SHELL_H */
