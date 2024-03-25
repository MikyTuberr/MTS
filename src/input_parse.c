#include "input_parse.h"

char **mts_split_line(char *line) {
    int bufsize = MTS_TOK_BUFSIZE;
    int pos = 0;
    char **tokens = (char**)malloc(bufsize*sizeof(char*));
    char *token;

    if(tokens == NULL) {
        perror("mts: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, MTS_TOK_DELIM);
    while(token != NULL) {
        tokens[pos] = token;
        pos++;

        if(pos >= bufsize) {
            bufsize += MTS_TOK_BUFSIZE;
            tokens = realloc(tokens,bufsize*sizeof(char*));
            if (tokens == NULL) {
                perror("mts: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, MTS_TOK_DELIM);
    }

    tokens[pos] = NULL;
    return tokens;
}

char *mts_read_line(void) {
    char *str = NULL;
    size_t len = 0;

    if (getline(&str, &len, stdin) == -1) {
        if (feof(stdin)) {
            exit(EXIT_SUCCESS);
        }
        else {
        perror("mts_read_line"); 
        exit(EXIT_FAILURE);
        }
    }
    
    return str;
}