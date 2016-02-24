#include <stdio.h>

int myabs(int a) {
    if (a >= 0) {
        return a;
    } else {
        return -a;
    }
}

int main() {
    printf("%d\n", myabs(5));
    printf("%d\n", myabs(-5));
}
