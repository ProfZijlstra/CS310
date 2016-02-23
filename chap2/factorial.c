/* factorial function computes n! for nonnegative n 
   version 1 */

int factorial(int n) {
    int ans = 1;
    while (n > 1) {
        ans = ans * n;
        n = n - 1;
    }
    return ans;
}

#include <stdio.h>

int main () {
    int n;
    printf("Please enter value of n=");
    scanf("%d", &n);
    if (n >= 0) {
        printf("factorial(%d)=", n);
        printf("%d\n", factorial(n));
    } else {
        printf("factorial of a negative number is undefined\n");
    }
}
