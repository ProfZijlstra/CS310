#include <unistd.h>
#include <stdio.h>
#define DIM 8

int main() {
    int arr[DIM] = {1,2,3,4,5,6,7,8};
    int pid = fork();
    int ans, i;
    if (pid == 0) {
        ans = 0;
        for (i = 0; i < DIM; i++) {
            ans += arr[i];
            printf("Child: sum = %d\n", ans);
           // sleep(1);
        }
        _exit(0);
    } else if (pid < 0) {
        printf("Fork failed to create a child!\n");
        return 1;
    } else {
        ans = 1;
        for (i = 0; i < DIM; i++) {
            ans *= arr[i];
            printf("Parent: product = %d\n", ans);
          //  sleep(1);
        }
    }
}

