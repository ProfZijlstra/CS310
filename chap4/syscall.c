#include <stdio.h>
#include <stdlib.h>

#define SYSCALL(val, fn, arglist, errval)               \
{                                                       \
    val = fn arglist; /* call fn  */                    \
    if ( (errval) == val) {                             \
        fprintf(stderr, "The call to %s failed\n", #fn);\
        exit(1);                                        \
    }                                                   \
}

int main() {
    FILE *fp;
    SYSCALL(fp, fopen, ("bad-file-name", "r"), NULL)
    printf("After SYSCALL");
}

