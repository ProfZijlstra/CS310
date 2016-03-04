#include <stdio.h>

/*
union int_or_float {
    int ival;
    float fval;
};
*/

typedef union {
    int ival;
    float fval;
} Int_or_float;

int main() {
    Int_or_float x;
    x.ival = 5;
    printf("%d\n", x.ival);
    x.fval = 12.34;
    printf("%f\n", x.fval);
    printf("%d\n", x.ival);
}
