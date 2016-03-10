#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    argv++; // skip program name

    // split argv on % separator into two commands
    int sep;
    for (sep = 1; sep < argc; sep++) { // start at likely place for sep
        if (strcmp(argv[sep], "%") == 0) {
            argv[sep] = '\0'; // break cmdline into two strings
            break;
        }
    }

    // make pipe
    int fds[2];
    pipe(fds);

    // second child, runs second command, and reads from pipe (it's stdin)
    int pid2;
    if ( (pid2 = fork()) == 0) {
        close(fds[1]);   // close the write end
        dup2(fds[0], 0); // 0 (stdin) becomes duplicate of fds[0]
        close(fds[0]);   // close the read end (stdin from pipe will still work)
        execv(argv[sep+1], &argv[sep+1]); // it's stdin reads from pipe
        _exit(1);        // bad exit, execv failed
    }

    // first child, runs first command, and writes to the pipe (it's stdout)
    int pid1;
    if ( (pid1 = fork()) == 0) {
        close(fds[0]);   // close the read end
        dup2(fds[1], 1); // 1 (stdout) becomes duplicate of fds[1]
        close(fds[1]);   // close the write end (stdout to pipe will still work)
        execv(argv[0], argv); // it's stdout writes to pipe
        _exit(1);        // bad exit, execv failed
    }

    // parent doesn't use pipe
    close(fds[0]);
    close(fds[1]);

    // do I need to wait???
    int status;
    while (wait(&status) != pid2);
    if (status == 0) {
        printf("Child 2 terminated\n");
    } else {
        printf("Child 2 failed\n");
    }
}
