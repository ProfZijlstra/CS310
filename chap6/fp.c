#include <stdio.h>

int average(int x, int y) {
    return (x+y) / 2;
}

int main() {
    int (*fn)(int, int);
    fn = &average; // also fn = average
    int a = fn(14,26); // also (*fn)(14,24)
    printf("Average of 14 and 26: %d\n", a);
}

/*
    // we can also make a typedef 
    // for functions with such a signature
    typedef int (* INT_FN)(int, int);
    INT_FN f2;
    f2 = average;
    int x = f2(8, 12);
    printf("Average of 8 and 12: %d\n", x);
    */


