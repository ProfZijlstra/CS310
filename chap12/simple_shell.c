#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define MAXLINE 80
#define MAXARG 20
#define WHITE " \n\t"

void background(char* cmd) {
    // fill argv
    char* argv[MAXARG+1];
    int i = 0;
    char* tok = strtok(cmd, WHITE);
    argv[i++] = tok;
    while (i < MAXARG && tok != NULL) {
        // last tok will be NULL
        argv[i++] = tok = strtok(NULL, WHITE); 
    } 
    // fork and then exec the command
    int id = fork();
    if (id == 0) {
        execv(argv[0], argv);
        _exit(1); // if we get here execv failed
    } else if (id < 0) {
        fprintf(stderr, "fork failed\n");
        perror("background");
    }
}

int main() {
    char cmd[MAXLINE];
    while (1) {
        printf("mysh ready$ ");
        fgets(cmd, MAXLINE-1, stdin);
        background(cmd);
    }
}

