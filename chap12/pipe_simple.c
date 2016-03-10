#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fds[2];
    char buffer[20];
    int pid;
    pipe(fds);
    if ( (pid = fork()) == 0) {
        close(fds[1]); // child closes writing
        int i;
        while ( (i = read(fds[0], buffer, 6))!= 0 ) {
            buffer[i] = '\0'; //terminate what was read 
            printf("%d chars :%s: received by child\n", i, buffer);
        }
        _exit(0);
    }
    close(fds[0]); // parent closes reading
    write(fds[1], "Hello there", sizeof("Hello there"));
    write(fds[1], " from me.", sizeof(" from me."));
    close(fds[1]); //finished writing, effectively EOF

    int status = 0;
    while (wait(&status) != pid); // wait for child
    if (status == 0) {
        printf("child finished\n");
    } else {
        printf("child failed\n");
    }
}
