#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct sigaction action;

    printf("Ignoring SIGINT for 5 seconds\n");
    action.sa_handler = SIG_IGN;
    sigaction(SIGINT, &action, NULL);

    sleep(5);

    action.sa_handler = SIG_DFL;
    sigaction(SIGINT, &action, NULL);
    printf("No longer Ignoring SIGINT\n");

    while (1); // infinite loop
}

