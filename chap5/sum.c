#include <stdio.h>
#include <stdarg.h>

int sum(int argcnt, ...) {
    int ans = 0;
    va_list ap; // argument pointer

    // needs last named arg to find start
    va_start(ap, argcnt); 
    while (argcnt > 0) {
        // needs type to know size
        ans += va_arg(ap, int); 
        argcnt--;
    }
    va_end(ap); // cleanup
    return ans;
}

int main() {
    int total = 0;
    total = sum(10, 7, 4, 9, 2, 6, 1, 120, 40, 77, 51);
    printf("Sum of 1,2,3,4,5: %d\n", total);
}

