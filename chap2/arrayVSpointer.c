#include <stdio.h>

int main() {
    int a[10];
    int b = 5;
    int *c = &b;

    c = a; // perfectly legal
    a = c; // compile time error
}
