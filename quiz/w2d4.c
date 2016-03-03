#include <stdio.h>

void apply(int *a, int l, void (*doit)(int*)) {
    for (int i = 0; i < l; i++) {
        doit(&a[i]);
    }
}

void add1(int *p) {
    *p += 1;
}

void mod2(int *p) {
    *p = *p % 2;
}

int main() {
    int a[] = {1,2,3,4,5};
    apply(a, 5, add1);
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    apply(a, 5, mod2);
    for (int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
