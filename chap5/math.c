#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Need 2 numbers\n");
        return 1;
    }
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    printf("%f to the %f power is: %f\n", a, b, pow(a,b));
}


