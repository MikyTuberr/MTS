#ifndef INPUT_PARSE_H
#define INPUT_PARSE_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define MTS_TOK_BUFSIZE 64
#define MTS_TOK_DELIM " \t\r\n\a"

char **mts_split_line(char *line);
char *mts_read_line(void);

#endif /* INPUT_PARSE_H */