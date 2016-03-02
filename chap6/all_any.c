#include <ctype.h>
#include <stdio.h>

// int isupper(int c)

int all(int (*fp)(int), const char* a) {
    register int i;
    for (i = 0; a[i] != '\0'; i++) {
        if (!fp(a[i])) {
            return 0;
        }
    }
    return 1;
}

int any(int (*fp)(int), const char *a) {
    register int i;
    for (i=0; a[i] != '\0'; i++) {
        if (fp(a[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char a[] = "stringwithalllowercase";
    char b[] = "STRING WITH NO LOWER CASE";
    char c[] = "STRING with SOME lower CASE";

    if (all(islower, a)) {
        printf("It works!\n");
    } else {
        printf("That's strange, they're all lower\n");
    }
    if (all(islower, c)) {
        printf("That's strange, they're not all lower\n");
    } else {
        printf("It works!\n");
    }

    if (any(isupper, b)) {
        printf("That's strange, none are lower\n");
    } else {
        printf("It works!\n");
    }
}


