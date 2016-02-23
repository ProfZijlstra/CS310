#include <stdio.h>

int main() {
    int a = 512;
    int *b = &a;
    printf("%d %d %d\n", a, b[0], *b);
    *b = 8;
    printf("%d %d %d\n", a, b[0], *b);
}
