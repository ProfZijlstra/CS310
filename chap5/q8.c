#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double sum(char *fmt, ...) {
    double sum = 0;
    va_list ap;
    va_start(ap, fmt);
    for (int i = 0; fmt[i] != '\0'; i++) {
        switch(fmt[i]) {
            case 'i':
                sum += va_arg(ap, int);
                break;
            case 'd':
                sum += va_arg(ap, double);
                break;
            default:
                fprintf(stderr, "unknown type %c\n", fmt[i]);
        }
    }
    va_end(ap);
    return sum;
}

int main() {
    double total = sum("idddi", 5, 3.2, 8.9, 0.6, 7);
    printf("Total: %f\n", total);
}
