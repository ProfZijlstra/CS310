#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    if (fork() == 0) {
        //char* argv[2];
        //argv[0] = "/bin/date";
        //argv[1] = NULL;
        //execv(argv[0], argv);
        execl("/bin/date", "date", NULL);
        _exit(0);
    }
    union wait status;
    wait(&status);
    printf("This is the parent saying hi!\n");
}
