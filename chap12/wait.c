#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int pid;
    union wait status;
    if ( (pid = fork() == 0)) {
        printf("Child pid: %d\n", getpid());
        _exit(0);
    }
    printf("forking again\n");
    if ( (pid = fork() == 0)) {
        printf("Child pid: %d\n", getpid());
        _exit(1);
    }
    printf("first wait\n");
    pid = wait(&status);
    printf("pid=%d, status=%d\n", pid, status);
    printf("second wait\n");
    pid = wait(&status);
    printf("pid=%d, status=%d\n", pid, status);
}

