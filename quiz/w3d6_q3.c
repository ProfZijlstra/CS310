#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num = (rand() % 25) + 1;

    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[0]);// close read part of pipe
        num = (rand() % 25) + 1;
        int w = write(fd[1], &num, sizeof(int));
        while (w > 0) {
            num = (rand() % 25) + 1;
            w = write(fd[1], &num, sizeof(int));
        }
        _exit(0);
    }
    
    close(fd[1]); // close write part of pipe
    int guess;
    int count = 1;
    int r = read(fd[0], &guess, sizeof(int));
    while (guess != num && r > 0) {
        r = read(fd[0], &guess, sizeof(int));
        count++;
    }
    close(fd[0]); // makes the child write fail
    printf("Child took %d guess(es) to find %d\n", count, num);
}
