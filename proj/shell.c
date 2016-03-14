#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 80
#define MAXARG 20
#define WHITE " \n\t"

// turn the given command into tokens
void tokenize(char* cmd, char* argv[]) {
    int i = 0;
    char* tok = strtok(cmd, WHITE);
    argv[i++] = tok;
    while (i < MAXARG && tok != NULL) {
        // last tok will be NULL
        argv[i++] = tok = strtok(NULL, WHITE); 
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
    char cmd[MAXLINE+1];
    char* argv[MAXARG+1];
    char* got;

    while (1) {
        printf("mysh ready$ ");
        got = fgets(cmd, MAXLINE, stdin);
        if (got == NULL) { // user pressed ^D
            printf("\n");
            exit(0); 
        }
        tokenize(cmd, argv);
        background(argv);
    }
}

