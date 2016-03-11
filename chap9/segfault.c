#include <stdio.h>

int main() {
    int a[10];
    for (int i = 0; i < 100; i++) {
        a[i] = i;
    }
    printf("%d\n", a[99]);
}
