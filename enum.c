#include <stdio.h>

typedef enum {JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} Month;

int main() {
    Month now = FEB;
    printf("%d\n", now);
}
