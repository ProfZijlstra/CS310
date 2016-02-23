#include <stdio.h>

int global = 0;

void testA() {
    global++;
}

void testB() {
    global += 2;
}

int main() {
    testA();
    testB();
    printf("%d\n", global);
}

