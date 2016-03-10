#include <unistd.h>
#include <stdio.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("I'm a child! My pid is: %d my parent is: %d\n", 
                getpid(), getppid());
        _exit(0);
    } else if (pid < 0) {
        printf("Fork failed to create a child!\n");
        return 1;
    } else {
        printf("I %d called fork and made child: %d and my parent was: %d\n", 
                getpid(), pid, getppid());
    }
}

