#include <stdlib.h>
#include <stdio.h>

int *array_add(const int a[], const int b[], size_t n) {
    int *ans = (int *) calloc(n, sizeof(int));
    //int ans[n];
    for (int i = 0; i < n; i++) {
        ans[i] = a[i] + b[i];
    }
    return ans;
}

int main() {
    int a[] = {10, 20, 30};
    int b[] = {-1, -2, -3};
    int *sum = array_add(a, b, 3);
    for (int i = 0; i < 3; i++) {
        printf("%d ", sum[i]);
    }
    printf("\n");
    free(sum);

    int foo[] = {1,2,3,4,5};
    int bar[] = {1,1,1,1,1};
    sum = array_add(foo, bar, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", sum[i]);
    }
    printf("\n");
    free(sum); // exiting main will also free
}
