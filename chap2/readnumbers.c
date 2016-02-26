#include <stdio.h>

int main() {
    int nums[5];
    for (int i = 0; i < 5; i++) {
        scanf("%d", &nums[i]);
    }
    printf("Your numbers are:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", nums[i]);
    }

}
