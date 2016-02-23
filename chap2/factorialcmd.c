#include <stdio.h> 
#include <stdlib.h> // provides atoi

int factorial(int n) {
    int ans = 1;
    while (n > 1) {
        ans = ans * n;
        n = n - 1;
    }
    return ans;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please run with one argument");
        return 1;
    }
    int n = atoi(argv[1]);
    printf("factorial(%d)=%d\n", n, factorial(n));
    return 0;
}
