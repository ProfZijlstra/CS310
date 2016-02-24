#include <stdio.h>

int myround(float f) {
    return (int) (f + 0.5);
}

int main() {
    printf("%d\n", myround(3.4));
    printf("%d\n", myround(3.5));
    printf("%d\n", myround(3.6));
}
