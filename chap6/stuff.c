#include <stdio.h>
/*
int *a;
int m[] = {1, 2, 3, 4};
a = m; // now we can use it
a[3] = a[0] + 5 * a[1];
// now m[3] is also 11

char *s;
s = (char *) malloc()4 * sizeof(char);
s[0] = 'A';
s[1] = 'B';
s[2] = 'C';
s[3] = '\0';

int k, *a, **t;
t = &a;
a = &k;
**t = 15;
printf("%d %d %d\n", k, *a, **t);
*/

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int *b = a;
    &b[3] == a + 3 ? puts("same") : puts("diff");
    &a[3] == a + 3 ? puts("same") : puts("diff");
    printf("%d %d\n", a[3], *(a + 3));
}

