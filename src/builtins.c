#include "builtins.h"

char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};

int (*builtin_func[]) (char **) = {
    &mts_cd,
    &mts_help,
    &mts_exit
};

int mts_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

int mts_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "mts: expected argument to \"cd\"\n");
    } 
    else {
        if (chdir(args[1]) != 0) {
            perror("mts");
        }
    }
    return 1;
}

int mts_help(char **args) {
    printf("MikyTuberr's MTS\n");
    printf("The following are built in:\n");

    int n = mts_num_builtins();
    for (int i = 0; i < n; i++) {
        printf("  %s\n", builtin_str[i]);
    }
    return 1;
}

int mts_exit(char **args) {
    return 0;
}