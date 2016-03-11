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
    sigaction(SIGINT, &action, NULL); // ^C
    sigaction(SIGQUIT, &action, NULL); // ^\ . 
    sigaction(SIGTERM, &action, NULL); // normal kill . 
    while (1); // infinite loop
}

