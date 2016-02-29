#include <stdio.h>

int main() {
    char* a = "Hello";
    char* b = "World";
    char buf[13];
    snprintf(buf, 13, "%s %s\n", a, b);
    printf("%s", buf);
}
