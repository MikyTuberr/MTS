#include "core.h"

int mts_launch(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if(pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("mts");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid == -1) {
        perror("mte");
    }
    else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int mts_execute(char **args) {
    if(args[0] == NULL) {
        return 1;
    }
    int n = mts_num_builtins();
    for(int i=0;i < n; i++) {
        if(strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }

    return mts_launch(args);
}

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define PATH_MAX 1024
void mts_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        char *username = getlogin(); 
        char cwd[PATH_MAX];

        if (username == NULL) {
            struct passwd *pw = getpwuid(getuid());
            if (pw != NULL) {
                username = pw->pw_name;
            } else {
                perror("getpwuid() error");
                return;
            }
        }

        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RED "@" ANSI_COLOR_BLUE "%s" ANSI_COLOR_RESET "(^) ", username, cwd);
        } else {
            perror("getcwd() error");
            return;
        }

        line = mts_read_line();
        args = mts_split_line(line);
        status = mts_execute(args);

        free(args);
        free(line);
    } while (status);
}