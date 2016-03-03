#include <stdlib.h>
#include <stdio.h>

int main() {
    void** array = malloc(10 * sizeof(void*));
    int ints[10] = {1,2,3,4,5,6,7,8,9,0};
    for (int i = 0; i < 10; i++) {
        array[i] = (void*)&ints[i];
    }

    for (int i = 0; i < 10; i++) {
        int *p = (int*)array[i];
        printf("%d ", *p);
    }
}
