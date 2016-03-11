#include <unistd.h>
#include <stdio.h>

int main() {
    if (fork() == 0) {
        printf("Hello\n");
        _exit(0);
    }
    if (fork() == 0) {
        printf("World\n");
        _exit(0);
    }
}
