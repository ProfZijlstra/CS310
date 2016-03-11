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
        while (r) {
            r = read(pipeAB[0], &buf, 1);
            if (r) {
                printf("Process B received: %c\n", buf);
                write(pipeBC[1], &buf, r);
            }
        } 
        close(pipeAB[0]);
        close(pipeBC[1]);
        _exit(0);
    }

    // second child is process C
    if (fork() == 0) {
        close(pipeAB[0]);
        close(pipeAB[1]);
        close(pipeBC[1]); // C can only read from this pipe
        close(pipeCA[0]); // C can only write to this pipe
        while (r) {
            r = read(pipeBC[0], &buf, 1);
            if (r) {
                printf("Process C received: %c\n", buf);
                write(pipeCA[1], &buf, r);
            }
        } 
        close(pipeBC[0]);
        close(pipeCA[1]);
        _exit(0);
    }
    
    // A is parent process
    close(pipeBC[0]); // not needed by A
    close(pipeBC[1]); // not needed by A
    close(pipeAB[0]); // A can only write into this pipe
    close(pipeCA[1]); // A can only read from this pipe
    int out = 'A';
    int in = 0;
    write(pipeAB[1], &out, 1);
    read(pipeCA[0], &in, 1);
    printf("Wrote: %c read: %c \n", out, in);

    // close the pipe will cause children to quit
    close(pipeAB[1]); // this causes B to read 0
    close(pipeCA[0]); // A no longer wants to read
}
