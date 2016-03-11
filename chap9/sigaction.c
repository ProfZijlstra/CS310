#include <signal.h>
#include <stdio.h>

void count(int sig) {
    static int count = 0;
    count++;
    printf("Total of %d INTTERUPTS received\n", count);
}

int main() {
    struct sigaction action;
    action.sa_handler = count;
    sigaction(SIGINT, &action, NULL);
    while (1); // infinite loop
}

