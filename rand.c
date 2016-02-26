#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    //printf("%d\n", RAND_MAX);
    srand(time(NULL));
    int r = rand();
    printf("%d\n", r);
    r = rand();
    printf("%d\n", r);
    r = rand();
    printf("%d\n", r);
    r = rand();
    printf("%d\n", r);
    //printf("Random number between 10 and 20: %d\n", (r %10) + 10);
}
