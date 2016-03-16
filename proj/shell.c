#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAXCHARS 80
#define MAXTOK 20
#define WHITE " \n\t"

// turn the given command into tokens
void tokenize(char* cmd, char* argv[]) {
    char* tok = strtok(cmd, WHITE);
    argv[0] = tok;
    int i;
    for (i = 1; i < MAXTOK && tok != NULL; i++) {
        // last tok will be NULL
        tok = strtok(NULL, WHITE); 
        argv[i] = tok;
    } 
}

// fork and then exec the tokenized command 
// don't wait for it to finish (run in the background)
// prompt therefore usually re-appears first, then child output
int background(char* argv[]) {
    int id = fork();
    if (id == 0) {
        execv(argv[0], argv);
        _exit(1); // if we get here execv failed
    } else if (id < 0) {
        fprintf(stderr, "fork failed\n");
        perror("background");
    }
    return id;
}

// main loop of the shell
int main() {
    char cmd[MAXCHARS];
    char* argv[MAXTOK+1];
    char* got;

    while (1) {
        printf("mysh ready$ ");
        // reads MAXCHARS -1 chars and adds '\0'
        got = fgets(cmd, MAXCHARS, stdin);
        if (got == NULL) { // user pressed ^D
            printf("\n");
            exit(0); 
        }
        tokenize(cmd, argv);
        background(argv);
    }
}

