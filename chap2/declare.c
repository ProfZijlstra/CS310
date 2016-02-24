#include <stdio.h>

int add(int x, int y);

int main() {
    printf("%d\n", add(4, 5));
    return 0;
}

int add(int x, int y) {
    return (x + y);
}
