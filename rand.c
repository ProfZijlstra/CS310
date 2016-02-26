#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("%d\n", RAND_MAX);
    printf("Random number between 0 and 10: %d\n", rand() %10);
}
