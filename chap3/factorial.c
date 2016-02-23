#include <stdio.h>

int factorial(int n) {
    if (n ==0) { // same as: if (!n)
        return 1;
    }
    return (n * factorial(n - 1));
}

int main() {
    printf("%d\n", factorial(5));
}
