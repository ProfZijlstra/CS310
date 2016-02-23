#include <stdio.h>

void testA() {
    extern int global;
    global++;
}

void testB() {
    extern int global;
    global += 2;
}

int main() {
    extern int global;
    testA();
    testB();
    printf("%d\n", global);
}

int global = 0;

