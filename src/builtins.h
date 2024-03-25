#ifndef BUILTINS_H
#define BUILTINS_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

extern char *builtin_str[];
extern int (*builtin_func[])(char **);

int mts_num_builtins();
int mts_cd(char **args);
int mts_help(char **args);
int mts_exit(char **args);

#endif /* BUILTINS_H */