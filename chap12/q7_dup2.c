#include <unistd.h>
#include <stdio.h>

int main() {
    // parent is process A
    int pipeAB[2];
    int pipeBC[2];
    int pipeCA[2];
    pipe(pipeAB);
    pipe(pipeBC);
    pipe(pipeCA);

    // each process will have their own copy of:
    int buf;
    int r = 1;

    // first child is process B
    if (fork() == 0) {
        close(pipeCA[0]);
        close(pipeCA[1]);
        close(pipeAB[1]); // B can only read from this pipe
        close(pipeBC[0]); // B can only write to this pipe
        
        // make incoming pipe stdin
        dup2(pipeAB[0], 0); // B's stdin now comes from incoming pipe
        close(pipeAB[0]); // close incoming pipe (alternate opening now)

        // make outgoing pipe stdout
        dup2(pipeBC[1], 1); // B's stdout now goes to outgoing pipe
        close(pipeBC[1]); // close outgoing pipe (alternate opening now)

        while (r) {
            r = read(0, &buf, 1);
            if (r) {
                buf++;
                write(1, &buf, r);
            }
        } 
        close(1); // close stdout, sends EOF signal along pipeBC
        close(0);
        _exit(0);
    }

    // second child is process C
    if (fork() == 0) {
        close(pipeAB[0]);
        close(pipeAB[1]);
        close(pipeBC[1]); // C can only read from this pipe
        close(pipeCA[0]); // C can only write to this pipe

        // make incoming pipe stdin
        dup2(pipeBC[0], 0); // C's stdin now comes from incoming pipe
        close(pipeBC[0]); // close incoming pipe (alternate opening now)

        // make outgoing pipe stdout
        dup2(pipeCA[1], 1); // C's stdout now goes to outgoing pipe
        close(pipeCA[1]); // close outgoing pipe (alternate opening now)

        while (r) {
            r = read(0, &buf, 1);
            if (r) {
                buf++;
                write(1, &buf, r);
            }
        } 
        close(1); // closing stdout sends EOF on pipeCA
        close(0);
        _exit(0);
    }
    
    // A is parent process
    close(pipeBC[0]); // not needed by A
    close(pipeBC[1]); // not needed by A
    close(pipeAB[0]); // A can only write into this pipe
    close(pipeCA[1]); // A can only read from this pipe

    // if A writes to 2 (stderr) it actually writes to stdout
    dup2(1, 2); // duplicate stdout so both 1 and 2 are now stdout

    // make incoming pipe stdin
    dup2(pipeCA[0], 0); // A's stdin now comes from incoming pipe
    close(pipeCA[0]); // close incoming pipe (alternate opening now)

    // make outgoing pipe stdout
    dup2(pipeAB[1], 1); // A's stdout now goes to outgoing pipe
    close(pipeAB[1]); // close outgoing pipe (alternate opening now)

    int out = 'q';
    int in = 0;
    write(1, &out, 1);
    read(0, &in, 1);
    fprintf(stderr, "Wrote: %c read: %c \n", out, in); // write to stdout!!!

    // close the pipe will cause children to quit
    close(pipeAB[1]); // this causes B to read 0
    close(pipeCA[0]); // A no longer wants to read
}
