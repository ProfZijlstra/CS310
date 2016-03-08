#include <stdio.h>
#include <math.h>

int main() {
    char *format = "%*.*f <- that's PI\n";
    printf(format, 10, 7, M_PI);
    printf(format, 5, 3, M_PI);
}
