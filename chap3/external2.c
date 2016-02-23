#include <stdio.h>

extern int test;
extern void tripple();

int main() {
    tripple();
    printf("%d\n", test);
}
