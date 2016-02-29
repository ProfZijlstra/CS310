#include <stdio.h>

int inner(const int *a, const int *b, int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += *a * *b;
        a++;
        b++;
    }
    return ans;
}

int main() {
    int a[] = {1, 2, 3};
    int b[] = {3, 2, 1};
    printf("%d\n", inner(a, b, 3));
}

