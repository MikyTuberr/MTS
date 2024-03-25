#ifndef CORE_H
#define CORE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pwd.h>
#include "input_parse.h"
#include "builtins.h"

int mts_launch(char **args);
int mts_execute(char **args);
void mts_loop(void);

#endif /* CORE_H */