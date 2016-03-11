#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fds[2];
    pipe(fds);

    if (fork() == 0) {
        close(fds[0]); // close read end in child
        dup2(fds[1], 1); // make stdout the pipe write end
        close(fds[1]); // close the normal pipe write end

        char* argv[2];
        argv[0] = "/bin/date";
        argv[1] = NULL;
        execv(argv[0], argv);
        _exit(0);
    }

    int status;
    wait(&status); // not actually checking if correct child

    // in parent
    close(fds[1]); // close write end
    char buf[10];
    read(fds[0], buf, 9); // read from the read end of pipe
    close(fds[0]); // close after reading

    // get the first word out of buf
    buf[9] = '\0'; // make sure string is terminated (strtok will do as well)
    char *tok = strtok(buf, " ");
    printf("Parent: %s\n", tok);
}
