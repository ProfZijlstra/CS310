#include <stdio.h>

int main() {
    for (int i = 0; i <= 10; i++) {
        printf("%d remainder mod 2 is: %d", i);
        if (i & 1) {
            printf(" odd\n");
        } else {
            printf(" even\n");
        }
    }
}
