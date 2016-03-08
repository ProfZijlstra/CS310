#include <stdio.h>

int main() {
    char buf[50];
    int i = 0;
    //scanf("%*s %4s %d", buf, &i);
    //printf("Your second and third things: %s, %d\n", buf, i);
    scanf("%49[^a-f]", buf);
    printf("You wrote: %s\n", buf);
}
